CPP=g++

VECTOR=ctvector.cpp ctvector.h
LINE=ctline.cpp ctline.h

build: $(VECTOR)
	$(CPP) -c -fPIC $(VECTOR)
	$(CPP) -c -fPIC $(LINE)
	$(CPP) -shared -Wl,-soname,libctvector.so -o libctvector.so *.o
openblas: $(VECTOR)
	$(CPP) -c -fPIC $(VECTOR) -Dopenblas -lopenblas
	$(CPP) -c -fPIC $(LINE) -Dopenblas -lopenblas
	$(CPP) -shared -Wl,-soname,libctvector.so -o libctvector.so *.o
install:
	mkdir /usr/include/ctvector
	cp libctvector.so /usr/lib/
	cp ctvector.h /usr/include/ctvector/
	cp ctline.h /usr/include/ctvector/
uninstall:
	rm /usr/lib/libctvector.so
	rm -r /usr/include/ctvector
clean:
	rm *.o *.so *.gch
