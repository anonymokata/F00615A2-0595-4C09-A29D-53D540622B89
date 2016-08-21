lib_object = libroman_calculator.a
objects = conversions.o roman_calculator.o

$(lib_object) : $(objects)
	$(AR) rv $(lib_object) $(objects)
	$(RANLIB) $(lib_object)

conversions.o : conversions.c
	$(COMPILE) -c conversions.c

roman_calculator : roman_calculator.c
	$(COMPILE) -c roman_calculator.c

.PHONY: clean
clean :
	rm -f $(lib_object) $(objects)
