CXXFLAGS= -c -g -std=c++11 -iquote inc -Iinc/PodstawoweElementy -Iinc/Templates -Wall -pedantic
TRGDIR= ./test_lazika
OBJ= ./obj

#Pomocnicze oznaczenia folderow

PODSTINC= inc/PodstawoweElementy
PODSTSRC= src/PodstawoweElementy
TEMPL= inc/Templates


___start___: ${TRGDIR}/test_lazikap
	${TRGDIR}/test_lazikap

${TRGDIR}:
	mkdir -p ${TRGDIR}

${OBJ}:
	mkdir -p ${OBJ}

${TRGDIR}/test_lazikap: ${OBJ}/main.o ${OBJ}/ObiektGeom.o ${OBJ}/Wektor3D.o
	g++ -o ${TRGDIR}/test_lazikap ${OBJ}/main.o ${OBJ}/ObiektGeom.o ${OBJ}/Wektor3D.o

${OBJ}/main.o: src/main.cpp ${PODSTINC}/Wektor3D.hh
	g++ ${CXXFLAGS} -o ${OBJ}/main.o src/main.cpp

${OBJ}/ObiektGeom.o: src/ObiektGeom.cpp inc/ObiektGeom.hh ${PODSTINC}/Macierz3D.hh ${PODSTINC}/Wektor3D.hh 
	g++ ${CXXFLAGS} -o ${OBJ}/ObiektGeom.o src/ObiektGeom.cpp

${OBJ}/Wektor3D.o: ${PODSTSRC}/Wektor3D.cpp ${TEMPL}/SWektor.hh
	g++ ${CXXFLAGS} -o ${OBJ}/Wektor3D.o ${PODSTSRC}/Wektor3D.cpp