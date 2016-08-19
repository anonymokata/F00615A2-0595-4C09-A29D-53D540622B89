lib_object = libroman_calculator.a
objects = conversions.o

$(lib_object) : $(objects)
	$(AR) rv $(lib_object) $(objects)
	$(RANLIB) $(lib_object)

conversions.o : conversions.c
	$(COMPILE) -c conversions.c

.PHONY: clean
clean :
	rm -f $(lib_object) $(objects)
