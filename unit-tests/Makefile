test_object = unit_tests
objects = test_runner.o test_conversions.o test_validations.o test_roman_calculator.o

$(test_object) : $(objects)
	$(LD) -o $(test_object) $(objects) -L../src -lroman_calculator -lcheck -lpthread -lrt -lm

test_runner.o : test_runner.c 
	$(COMPILE) -c test_runner.c

test_validations.o : test_validations.c ../src/validations.c 
	$(COMPILE) -c test_validations.c

test_conversions.o : test_conversions.c ../src/conversions.c 
	$(COMPILE) -c test_conversions.c

test_roman_calculator.o : test_roman_calculator.c ../src/roman_calculator.c 
	$(COMPILE) -c test_roman_calculator.c

.PHONY: check
check: $(test_object)
	./$(test_object)

.PHONY: clean
clean :
	rm -f $(test_object) $(objects)
