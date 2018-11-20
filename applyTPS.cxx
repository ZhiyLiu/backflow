//
// Created by jphong on 2/16/18.
//

#include "thinplatesplinepdmtosrep.h"
//#include "itkTransformFactoryBase.h"
//#include "itkTransformFactory.h"
//#include "itkTransformFileReader.h"
#include "itkThinPlateSplineExtended.h"

#include <iostream>
#include <string>


int main( int argc, char* argv[] ){

	if( argc != 5 ) {
		std::cerr << "Usage: "<< std::endl;
		std::cerr << argv[0];
		std::cerr << " <Template s-rep, tpsFileName, sourceLandMark and outputPrefix>";
		std::cerr << std::endl;
		return EXIT_FAILURE;
	}


	typedef double CoordinateRepType;
	typedef itkThinPlateSplineExtended TransformType;
	typedef itk::Point< CoordinateRepType, 3 > PointType;
	typedef std::vector< PointType > PointArrayType;
	typedef TransformType::PointSetType PointSetType;
	typedef PointSetType::Pointer PointSetPointer;
	typedef PointSetType::PointIdentifier PointIdType;


	thinplatesplinepdmtosrep obj;
	std::string templateModelName=argv[1];
	std::string transformFileName=argv[2];
	std::string sourceLandMarkFileName=argv[3];
	std::string outputPrefix=argv[4];

	ifstream inFile;
	inFile.open(transformFileName.c_str());
	if(!inFile) {
		std::cerr << "Unable to open the file: " << transformFileName << std::endl;
		return EXIT_FAILURE;
	}
	itkThinPlateSplineExtended::DMatrixType D;
	itkThinPlateSplineExtended::AMatrixType A;
	itkThinPlateSplineExtended::BMatrixType B;
	// first read in the size
	string buffer;
	std::getline(inFile,buffer);
	std::istringstream ss1(buffer);
	int nRows = 0;
	int nCols = 0;
	char tmp;
	ss1 >> nRows >> tmp >> nCols;
	D.set_size(nRows,nCols);
	for(int i = 0; i < nRows; i++) {
		for(int j = 0; j < nCols; j++) {
			string buffer2;
			std::getline(inFile, buffer2, ',');
			double entry = atof(buffer2.c_str());
			D(i,j) = entry;
		}
	}
	buffer.clear();
	std::getline(inFile, buffer);
	std::getline(inFile, buffer);
	for(int i = 0; i < A.rows(); i++) {
		for(int j = 0; j < A.cols(); j++) {
			string buffer2;
			std::getline(inFile, buffer2,',');
			double entry = atof(buffer2.c_str());
			A(i,j) = entry;
		}
	}
	buffer.clear();
	std::getline(inFile, buffer);
	std::getline(inFile, buffer);
	for(int i = 0; i < B.size(); i++) {
		string buffer2;
		std::getline(inFile, buffer2, ',');
		double entry = atof(buffer2.c_str());
		B(i) = entry;
	}
	TransformType::Pointer tps = TransformType::New();
	tps->setDMatrix(D);
	tps->setAMatrix(A);
	tps->setBVector(B);

	PointSetType::Pointer sourceLandMarks = PointSetType::New();
	PointSetType::PointsContainer::Pointer sourceLandMarkContainer = sourceLandMarks->GetPoints();
	vtkSmartPointer<vtkPolyDataReader> reader_source = vtkSmartPointer<vtkPolyDataReader>::New();
	vtkSmartPointer<vtkPolyData> polyData_source = vtkSmartPointer<vtkPolyData>::New();
	reader_source->SetFileName(sourceLandMarkFileName.c_str());
	reader_source->Update();
	polyData_source = reader_source->GetOutput();
	PointIdType id_s = itk::NumericTraits< PointIdType >::Zero;
	PointType p1;
	// Read in the source points set
	for(unsigned int i = 0; i < polyData_source->GetNumberOfPoints(); i += 10){
		double p[3];
		polyData_source->GetPoint(i,p);
		// This is identical to:
		// polydata->GetPoints()->GetPoint(i,p);
		p1[0] = p[0];
		p1[1] = p[1];
		p1[2] = p[2];
		sourceLandMarkContainer->InsertElement(id_s, p1);
		id_s++;
	}
	tps->SetSourceLandmarks(sourceLandMarks);
//	itk::TransformFactory<TransformType>::RegisterTransform();
//	typedef itk::TransformFileReader TransformReaderType;
//	TransformReaderType::Pointer reader = TransformReaderType::New();
//	reader->SetFileName(trasformFileName.c_str());
//	try {
//		reader->Update();
//	}
//	catch(itk::ExceptionObject & excp) {
//		std::cerr << "Error while reading the transform file" << std::endl;
//		std::cerr << excp << std::endl;
//		std::cerr << "[FAILED]" << std::endl;
//		return EXIT_FAILURE;
//	}

//	TransformReaderType::TransformListType * transforms =
//			reader->GetTransformList();
	toolsfunc tls;
//	TransformReaderType::TransformListType::iterator it = transforms->begin();
//	TransformType::Pointer tps = static_cast<TransformType*>(it->GetPointer());

	M3DQuadFigure* quadFig = tls.GetQuadFigure(templateModelName.c_str());
	int rowNums = quadFig->getRowCount();
	int colNums = quadFig->getColumnCount();

	// Loop each atom
	for(unsigned int u = 0; u < rowNums; u++){
		for(unsigned int v = 0; v < colNums; v++){
			// For up and down spokes
			M3DQuadPrimitive* prim = dynamic_cast<M3DQuadPrimitive*>(quadFig->getPrimitivePtr(u,v));
			// Skeletal point
			Vector3D tail = prim->getX();
			// Up boundary point
			Vector3D up_tip = prim->getX() + prim->getR0()*prim->getU0();
			// Down boundary point
			Vector3D down_tip = prim->getX() + prim->getR1()*prim->getU1();

			// Performance tps on these three points
			PointType transformed_tail = tps->TransformPoint(
					obj.Vector3DtoPointType(tail));
			PointType transformed_up_tip = tps->TransformPoint(
					obj.Vector3DtoPointType(up_tip));
			PointType transformed_down_tip = tps->TransformPoint(
					obj.Vector3DtoPointType(down_tip));

			// Get transformed spoke radius and direction
			double upSpokeRadiu = obj.calculateSpokeLength(transformed_tail, transformed_up_tip);
			double downSpokeRadiu = obj.calculateSpokeLength(transformed_tail, transformed_down_tip);

			Vector3D upSpokeDir = obj.calculateSpokeDirection(transformed_tail, transformed_up_tip);
			Vector3D downSpokeDir = obj.calculateSpokeDirection(transformed_tail, transformed_down_tip);

			// Set transformed spoke radius and direction to this atom
			prim->setR0(upSpokeRadiu);
			prim->setR1(downSpokeRadiu);
			prim->setU0(upSpokeDir);
			prim->setU1(downSpokeDir);

			// For crest spokes
			if(u==0 || u==rowNums-1 || v==0 || v==colNums-1) {
				M3DQuadEndPrimitive* endPrim = dynamic_cast<M3DQuadEndPrimitive*>(quadFig->getPrimitivePtr(u, v));
				Vector3D crest_tip = endPrim->getX() + endPrim->getREnd()*endPrim->getUEnd();

				PointType transform_crest_tip = tps->TransformPoint(
						obj.Vector3DtoPointType(crest_tip));

				// Get transformed spoke radius and direction
				double crestSpokeRadiu = obj.calculateSpokeLength(transformed_tail, transform_crest_tip);
				Vector3D crestSpokeDir = obj.calculateSpokeDirection(transformed_tail, transform_crest_tip);

				// Set transformed spoke radius and direction to this atom
				endPrim->setREnd(crestSpokeRadiu);
				endPrim->setUEnd(crestSpokeDir);
			}

			prim->setX(transformed_tail[0], transformed_tail[1], transformed_tail[2]);
		}
	}

	// Save this quadFig to m3d file
	Registry registry;
	registry.readFromFile(templateModelName.c_str(), false);

	// Write the changed quadFig to m3d file.
	char figureStr[1024];
	sprintf(figureStr, "model.figure[%d]", 0);//In m3d file, every figure is identified as figure[0], cannot change the index, why?
	quadFig->writeFigure(figureStr,registry); //write the figure into registry.

	string outputFileName = string(outputPrefix) + ".m3d";
	cout<<"----Write srep to: "<< outputFileName << endl;
	//overwrite the input file to save the changes for next loop.
	registry.writeToFile(outputFileName.c_str());
	cout<<"----Finished!" << endl;
	return EXIT_SUCCESS;
}