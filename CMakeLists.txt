cmake_minimum_required(VERSION 2.8)
project(MakeTextureCubeOBJ)
set(CMAKE_CONFIGURATION_TYPES "Debug;Release" 
CACHE STRING "My multi config types" FORCE)

SET("OpenCV_DIR" "C:/opencv3.1.0/build")
find_package(OpenCV REQUIRED)
# Qt library
find_package(Qt5Widgets)
find_package(Qt5OpenGL)
find_package (VTK REQUIRED) #for QT5_WRAP_CPP command 
# OpenGL & GLEW library
find_package(OpenGL)
#find_package(GLUT REQUIRED)

file(GLOB project_SOURCES *.cpp)
file(GLOB project_HEADERS *.h)
file(GLOB project_FORMS *.ui)

file(COPY "opencv_world310d.dll" DESTINATION "./")

QT5_WRAP_CPP (project_HEADERS_MOC   ${project_HEADERS})
QT5_WRAP_UI  (project_FORMS_HEADERS ${project_FORMS})

ADD_DEFINITIONS (${QT_DEFINITIONS})

ADD_EXECUTABLE (MakeTextureCubeOBJ 
${project_SOURCES} 
${project_HEADERS} 
${project_FORMS} 
${project_FORMS_HEADERS} 
${project_HEADERS_MOC}
)

qt5_use_modules (MakeTextureCubeOBJ Widgets OpenGL)
target_link_libraries(MakeTextureCubeOBJ ${QT_LIBRARIES} ${OPENGL_LIBRARIES} ${OpenCV_LIBS})