CPP=g++

VECTOR=ctvector.cpp ctvector.h
LINE=ctline.cpp ctline.h

build: $(VECTOR)
	$(CPP) -c -fPIC $(VECTOR)
	$(CPP) -c -fPIC $(LINE)
	$(CPP) -shared -Wl,-soname,libctvector.so -o libctvector.so *.o
install:
	[ -d /usr/include/ctvector ] || mkdir /usr/include/ctvector
	cp -f libctvector.so /usr/lib/
	cp -f ctvector.h /usr/include/ctvector/
	cp -f ctline.h /usr/include/ctvector/
uninstall:
	rm -f /usr/lib/libctvector.so
	[ -d /usr/include/ctvector ] && rm /usr/include/ctvector/*.h
	[ -d /usr/include/ctvector ] && rmdir /usr/include/ctvector
clean:
	for file in $$(ls *.o); do rm $$file; done
	for file in $$(ls *.so); do rm $$file; done
	for file in $$(ls *.gch); do rm $$file; done
