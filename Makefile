CXXFLAGS= -c -g -std=c++11 -iquote inc -Wall -pedantic
TRGDIR= ./test_lazika
OBJ= ./obj

___start___: ${TRGDIR}/test_lazikap
	${TRGDIR}/test_lazikap

${TRGDIR}:
	mkdir -p ${TRGDIR}

${OBJ}:
	mkdir -p ${OBJ}

${TRGDIR}/test_lazikap: ${OBJ} 
	g++ -o ${TRGDIR}/test_lazikap 