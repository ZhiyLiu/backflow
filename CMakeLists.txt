#----------------------------------------------------------------------------
# USER! : SET THE NAME OF YOUR EXECUTABLE
# Replace 'MyExe' by the name you want to give your executable.
# (a good policy is to give the executable the same name that the directory)

OPTION(BUILD_VTKSREPTEST OFF)

IF(BUILD_VTKSREPTEST)

INCLUDE_DIRECTORIES(${ITK_INCLUDE_DIRS})

#########################
SET ( EXE_NAME   srepTest  )
#########################

#----------------------------------------------------------------------------

#----------------------------------------------------------------------------
# EXECUTABLE SOURCES (TO BE COMPILED)
# EITHER LIST ALL .cxx, *.cpp, *.cc IN CURRENT DIR USING NEXT LINE:

#FILE(GLOB ${EXE_NAME}_SOURCES *.cxx *.cpp *.cc)

# OR MANUALLY LIST YOUR FILES WITH NEXT COMMAND (WITHOUT EXTENSION)
    SET ( ${EXE_NAME}_SOURCES
            srepTest.cxx
        )
#----------------------------------------------------------------------------

    INCLUDE_DIRECTORIES (

# USER! : Add here the directories holding the extra .h files you need
# e.g.
            ../../lib/mySampleLib

            )

#----------------------------------------------------------------------------
# DEPENDENCIES (LIBRARIES TO LINK WITH)
    SET ( ${EXE_NAME}_LINK_LIBRARIES
#    ${crea_LIBRARIES}
#    ${WXWIDGETS_LIBRARIES}
#    ${KWWidgets_LIBRARIES}
#    ${VTK_LIBRARIES}
            vtkFiltering
            vtkCommon
            vtkRendering
            itkvnl
            SRep
            SRepInterpolation
            SRepVisualization

            register
#    ${ITK_LIBRARIES}
#    ${GDCM_LIBRARIES}
#    ${BOOST_LIBRARIES}

# USER! : Add here those agmonst the various (?) PROJECT LIBRARIES
# you need for the current executable
# (If you created only one Library, don't forget it !...)

    )
#----------------------------------------------------------------------------

#----------------------------------------------------------------------------
# USER! : UNCOMMENT NEXT LINE IF YOU WANT A CONSOLE ON WINDOWS
# NB : YOUR MAIN MUST BE ADAPTED ALSO
#      SEE THE MACRO CREA_WXMAIN_WITH_CONSOLE IN creaWx.h
#SET(${EXE_NAME}_CONSOLE TRUE)
#----------------------------------------------------------------------------

#----------------------------------------------------------------------------
# CREATES AND INSTALLS THE EXE
CREA_ADD_EXECUTABLE( ${EXE_NAME} )
#----------------------------------------------------------------------------







#----------------------------------------------------------------------------
# USER! : SET THE NAME OF YOUR EXECUTABLE
# Replace 'MyExe' by the name you want to give your executable.
# (a good policy is to give the executable the same name that the directory)

#########################
SET ( EXE_NAME   srepCrestTest  )
#########################

#----------------------------------------------------------------------------

#----------------------------------------------------------------------------
# EXECUTABLE SOURCES (TO BE COMPILED)
# EITHER LIST ALL .cxx, *.cpp, *.cc IN CURRENT DIR USING NEXT LINE:

#FILE(GLOB ${EXE_NAME}_SOURCES *.cxx *.cpp *.cc)

# OR MANUALLY LIST YOUR FILES WITH NEXT COMMAND (WITHOUT EXTENSION)
    SET ( ${EXE_NAME}_SOURCES
            ${EXE_NAME}.cxx
        )
#----------------------------------------------------------------------------

    INCLUDE_DIRECTORIES (

# USER! : Add here the directories holding the extra .h files you need
# e.g.
            ../../lib/mySampleLib

            )

#----------------------------------------------------------------------------
# DEPENDENCIES (LIBRARIES TO LINK WITH)
    SET ( ${EXE_NAME}_LINK_LIBRARIES
#    ${crea_LIBRARIES}
#    ${WXWIDGETS_LIBRARIES}
#    ${KWWidgets_LIBRARIES}
#    ${VTK_LIBRARIES}
            vtkFiltering
            vtkCommon
            vtkRendering
            itkvnl
            SRep
            SRepInterpolation
            SRepVisualization

            register

#    ${ITK_LIBRARIES}
#    ${GDCM_LIBRARIES}
#    ${BOOST_LIBRARIES}

# USER! : Add here those agmonst the various (?) PROJECT LIBRARIES
# you need for the current executable
# (If you created only one Library, don't forget it !...)

    )
#----------------------------------------------------------------------------

#----------------------------------------------------------------------------
# USER! : UNCOMMENT NEXT LINE IF YOU WANT A CONSOLE ON WINDOWS
# NB : YOUR MAIN MUST BE ADAPTED ALSO
#      SEE THE MACRO CREA_WXMAIN_WITH_CONSOLE IN creaWx.h
#SET(${EXE_NAME}_CONSOLE TRUE)
#----------------------------------------------------------------------------

#----------------------------------------------------------------------------
# CREATES AND INSTALLS THE EXE
CREA_ADD_EXECUTABLE( ${EXE_NAME} )
#----------------------------------------------------------------------------



#----------------------------------------------------------------------------
# USER! : SET THE NAME OF YOUR EXECUTABLE
# Replace 'MyExe' by the name you want to give your executable.
# (a good policy is to give the executable the same name that the directory)

#########################
SET ( EXE_NAME   testQuasi  )
#########################

#----------------------------------------------------------------------------

#----------------------------------------------------------------------------
# EXECUTABLE SOURCES (TO BE COMPILED)
# EITHER LIST ALL .cxx, *.cpp, *.cc IN CURRENT DIR USING NEXT LINE:

#FILE(GLOB ${EXE_NAME}_SOURCES *.cxx *.cpp *.cc)

# OR MANUALLY LIST YOUR FILES WITH NEXT COMMAND (WITHOUT EXTENSION)
    SET ( ${EXE_NAME}_SOURCES
            ${EXE_NAME}.cxx
        )
#----------------------------------------------------------------------------

    INCLUDE_DIRECTORIES (

# USER! : Add here the directories holding the extra .h files you need
# e.g.
            ../../lib/mySampleLib

            )

#----------------------------------------------------------------------------
# DEPENDENCIES (LIBRARIES TO LINK WITH)
    SET ( ${EXE_NAME}_LINK_LIBRARIES
#    ${crea_LIBRARIES}
#    ${WXWIDGETS_LIBRARIES}
#    ${KWWidgets_LIBRARIES}
#    ${VTK_LIBRARIES}

            vtkFiltering
            vtkCommon
            vtkRendering
            itkvnl
            SRep
            SRepInterpolation
            SRepVisualization

            register

#    ${ITK_LIBRARIES}
#    ${GDCM_LIBRARIES}
#    ${BOOST_LIBRARIES}

# USER! : Add here those agmonst the various (?) PROJECT LIBRARIES
# you need for the current executable
# (If you created only one Library, don't forget it !...)

    )
#----------------------------------------------------------------------------

#----------------------------------------------------------------------------
# USER! : UNCOMMENT NEXT LINE IF YOU WANT A CONSOLE ON WINDOWS
# NB : YOUR MAIN MUST BE ADAPTED ALSO
#      SEE THE MACRO CREA_WXMAIN_WITH_CONSOLE IN creaWx.h
#SET(${EXE_NAME}_CONSOLE TRUE)
#----------------------------------------------------------------------------

#----------------------------------------------------------------------------
# CREATES AND INSTALLS THE EXE
CREA_ADD_EXECUTABLE( ${EXE_NAME} )

ENDIF(BUILD_VTKSREPTEST)
#----------------------------------------------------------------------------

#########################
# SET ( EXE_NAME   mcf_srep )
# #########################

#     SET ( ${EXE_NAME}_SOURCES
#             ${EXE_NAME}.cxx
#         )
# #----------------------------------------------------------------------------
# # DEPENDENCIES (LIBRARIES TO LINK WITH)
#     SET ( ${EXE_NAME}_LINK_LIBRARIES
#             vtkFiltering
#             vtkCommon
#             vtkRendering
#             itkvnl
#             SRep
#             SRepInterpolation
#             SRepVisualization
#             Correspondence
#             register
#         )
# #----------------------------------------------------------------------------
# # CREATES AND INSTALLS THE EXE
# CREA_ADD_EXECUTABLE( ${EXE_NAME} )

#----------------------------------------------------------------------------
#########################
SET ( EXE_NAME   tps_srep )
#########################

SET ( ${EXE_NAME}_SOURCES
        ${EXE_NAME}.cpp
        )
#----------------------------------------------------------------------------
# DEPENDENCIES (LIBRARIES TO LINK WITH)
SET ( ${EXE_NAME}_LINK_LIBRARIES
        vtkFiltering
        vtkCommon
        vtkRendering
        itkvnl
        SRep
        SRepInterpolation
        SRepVisualization
        Correspondence
        register
        )
#----------------------------------------------------------------------------
# CREATES AND INSTALLS THE EXE
CREA_ADD_EXECUTABLE( ${EXE_NAME} )
#----------------------------------------------------------------------------

#----------------------------------------------------------------------------
#########################
SET ( EXE_NAME   computePairwiseTPS )
#########################

SET ( ${EXE_NAME}_SOURCES
        ${EXE_NAME}.cxx
        )
#----------------------------------------------------------------------------
# DEPENDENCIES (LIBRARIES TO LINK WITH)
SET ( ${EXE_NAME}_LINK_LIBRARIES
        vtkFiltering
        vtkCommon
        vtkRendering
        itkvnl
        SRep
        SRepInterpolation
        SRepVisualization
        Correspondence
        register
        )
#----------------------------------------------------------------------------
# CREATES AND INSTALLS THE EXE
CREA_ADD_EXECUTABLE( ${EXE_NAME} )
#----------------------------------------------------------------------------

#----------------------------------------------------------------------------
#########################
SET ( EXE_NAME   applyTPS )
#########################

SET ( ${EXE_NAME}_SOURCES
        ${EXE_NAME}.cxx
        )
#----------------------------------------------------------------------------
# DEPENDENCIES (LIBRARIES TO LINK WITH)
SET ( ${EXE_NAME}_LINK_LIBRARIES
        ${ITK_LIBRARIES}
        vtkFiltering
        vtkCommon
        vtkRendering
        itkvnl
        SRep
        SRepInterpolation
        SRepVisualization
        Correspondence
        register
        )
#----------------------------------------------------------------------------
# CREATES AND INSTALLS THE EXE
CREA_ADD_EXECUTABLE( ${EXE_NAME} )
#----------------------------------------------------------------------------

#----------------------------------------------------------------------------
#########################
SET ( EXE_NAME   applyTps2NewSrep )
#########################

SET ( ${EXE_NAME}_SOURCES
        ${EXE_NAME}.cpp
        )
#----------------------------------------------------------------------------
# DEPENDENCIES (LIBRARIES TO LINK WITH)
SET ( ${EXE_NAME}_LINK_LIBRARIES
        ${ITK_LIBRARIES}
        vtkFiltering
        vtkCommon
        vtkRendering
        itkvnl
        SRep
        SRepInterpolation
        SRepVisualization
        Correspondence
        register
        )
#----------------------------------------------------------------------------
# CREATES AND INSTALLS THE EXE
CREA_ADD_EXECUTABLE( ${EXE_NAME} )
#----------------------------------------------------------------------------

#----------------------------------------------------------------------------
#########################
SET ( EXE_NAME   compute_pairwise_tps )
#########################

SET ( ${EXE_NAME}_SOURCES
        ${EXE_NAME}.cxx
        )
#----------------------------------------------------------------------------
# DEPENDENCIES (LIBRARIES TO LINK WITH)
SET ( ${EXE_NAME}_LINK_LIBRARIES
        ${ITK_LIBRARIES}
        vtkFiltering
        vtkCommon
        vtkRendering
        itkvnl
        SRep
        SRepInterpolation
        SRepVisualization
        Correspondence
        register
        )
#----------------------------------------------------------------------------
# CREATES AND INSTALLS THE EXE
CREA_ADD_EXECUTABLE( ${EXE_NAME} )
#----------------------------------------------------------------------------

#----------------------------------------------------------------------------
#########################
SET ( EXE_NAME   apply_tps )
#########################

SET ( ${EXE_NAME}_SOURCES
        ${EXE_NAME}.cxx
        )
#----------------------------------------------------------------------------
# DEPENDENCIES (LIBRARIES TO LINK WITH)
SET ( ${EXE_NAME}_LINK_LIBRARIES
        ${ITK_LIBRARIES}
        vtkFiltering
        vtkCommon
        vtkRendering
        itkvnl
        SRep
        SRepInterpolation
        SRepVisualization
        Correspondence
        register
        )
#----------------------------------------------------------------------------
# CREATES AND INSTALLS THE EXE
CREA_ADD_EXECUTABLE( ${EXE_NAME} )
#----------------------------------------------------------------------------