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

${TRGDIR}/test_lazikap: ${OBJ}/main.o ${OBJ}/ObiektGeom.o ${OBJ}/Wektor3D.o ${OBJ}/Macierz3D.o ${OBJ}/OperacjeMat.o ${OBJ}/Obiekt.o ${OBJ}/PowierzchniaMarsa.o ${OBJ}/GNUPlot.o ${OBJ}/Scena.o ${OBJ}/Lazik.o ${OBJ}/Kadlub.o ${OBJ}/Kolo.o
	g++ -o ${TRGDIR}/test_lazikap ${OBJ}/main.o ${OBJ}/ObiektGeom.o ${OBJ}/Wektor3D.o ${OBJ}/Macierz3D.o ${OBJ}/OperacjeMat.o ${OBJ}/Obiekt.o ${OBJ}/PowierzchniaMarsa.o ${OBJ}/GNUPlot.o ${OBJ}/Scena.o ${OBJ}/Lazik.o ${OBJ}/Kadlub.o ${OBJ}/Kolo.o

${OBJ}/main.o: src/main.cpp ${PODSTINC}/Wektor3D.hh ${PODSTINC}/Macierz3D.hh
	g++ ${CXXFLAGS} -o ${OBJ}/main.o src/main.cpp

${OBJ}/Scena.o: src/Scena.cpp inc/Obiekt.hh inc/lacze_do_gnuplota.hh inc/PowierzchniaMarsa.hh
	g++ ${CXXFLAGS} -o ${OBJ}/Scena.o src/Scena.cpp

${OBJ}/Lazik.o: src/Lazik.cpp
	g++ ${CXXFLAGS} -o ${OBJ}/Lazik.o src/Lazik.cpp

${OBJ}/Kolo.o: src/Kolo.cpp inc/ObiektGeom.hh
	g++ ${CXXFLAGS} -o ${OBJ}/Kolo.o src/Kolo.cpp

${OBJ}/Kadlub.o: src/Kadlub.cpp inc/ObiektGeom.hh
	g++ ${CXXFLAGS} -o ${OBJ}/Kadlub.o src/Kadlub.cpp

${OBJ}/Obiekt.o: src/Obiekt.cpp inc/ObiektGeom.hh
	g++ ${CXXFLAGS} -o ${OBJ}/Obiekt.o src/Obiekt.cpp

${OBJ}/PowierzchniaMarsa.o: src/PowierzchniaMarsa.cpp inc/lacze_do_gnuplota.hh
	g++ ${CXXFLAGS} -o ${OBJ}/PowierzchniaMarsa.o src/PowierzchniaMarsa.cpp

${OBJ}/GNUPlot.o: src/lacze_do_gnuplota.cpp
	g++ ${CXXFLAGS} -o ${OBJ}/GNUPlot.o src/lacze_do_gnuplota.cpp

${OBJ}/ObiektGeom.o: src/ObiektGeom.cpp inc/ObiektGeom.hh ${PODSTINC}/Macierz3D.hh ${PODSTINC}/Wektor3D.hh 
	g++ ${CXXFLAGS} -o ${OBJ}/ObiektGeom.o src/ObiektGeom.cpp

${OBJ}/Macierz3D.o: ${PODSTSRC}/Macierz3D.cpp ${PODSTINC}/OperacjeMat.hh ${TEMPL}/SMacierz.hh ${PODSTINC}/Wektor3D.hh
	g++ ${CXXFLAGS} -o ${OBJ}/Macierz3D.o ${PODSTSRC}/Macierz3D.cpp

${OBJ}/Wektor3D.o: ${PODSTSRC}/Wektor3D.cpp ${TEMPL}/SWektor.hh
	g++ ${CXXFLAGS} -o ${OBJ}/Wektor3D.o ${PODSTSRC}/Wektor3D.cpp

${OBJ}/OperacjeMat.o: ${PODSTSRC}/OperacjeMat.cpp
	g++ ${CXXFLAGS} -o ${OBJ}/OperacjeMat.o ${PODSTSRC}/OperacjeMat.cpp