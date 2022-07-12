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

${TRGDIR}/test_lazikap: ${OBJ}/main.o ${OBJ}/ObiektGeom.o ${OBJ}/Wektor3D.o ${OBJ}/Macierz3D.o ${OBJ}/OperacjeMat.o ${OBJ}/Obiekt.o
	g++ -o ${TRGDIR}/test_lazikap ${OBJ}/main.o ${OBJ}/ObiektGeom.o ${OBJ}/Wektor3D.o ${OBJ}/Macierz3D.o ${OBJ}/OperacjeMat.o ${OBJ}/Obiekt.o

${OBJ}/main.o: src/main.cpp ${PODSTINC}/Wektor3D.hh ${PODSTINC}/Macierz3D.hh
	g++ ${CXXFLAGS} -o ${OBJ}/main.o src/main.cpp

${OBJ}/Obiekt.o: src/Obiekt.cpp inc/ObiektGeom.hh
	g++ ${CXXFLAGS} -o ${OBJ}/Obiekt.o src/Obiekt.cpp

${OBJ}/ObiektGeom.o: src/ObiektGeom.cpp inc/ObiektGeom.hh ${PODSTINC}/Macierz3D.hh ${PODSTINC}/Wektor3D.hh 
	g++ ${CXXFLAGS} -o ${OBJ}/ObiektGeom.o src/ObiektGeom.cpp

${OBJ}/Macierz3D.o: ${PODSTSRC}/Macierz3D.cpp ${PODSTINC}/OperacjeMat.hh ${TEMPL}/SMacierz.hh ${PODSTINC}/Wektor3D.hh
	g++ ${CXXFLAGS} -o ${OBJ}/Macierz3D.o ${PODSTSRC}/Macierz3D.cpp

${OBJ}/Wektor3D.o: ${PODSTSRC}/Wektor3D.cpp ${TEMPL}/SWektor.hh
	g++ ${CXXFLAGS} -o ${OBJ}/Wektor3D.o ${PODSTSRC}/Wektor3D.cpp

${OBJ}/OperacjeMat.o: ${PODSTSRC}/OperacjeMat.cpp
	g++ ${CXXFLAGS} -o ${OBJ}/OperacjeMat.o ${PODSTSRC}/OperacjeMat.cpp