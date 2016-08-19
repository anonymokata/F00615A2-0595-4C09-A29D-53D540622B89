test_object = unit_tests
objects = test_conversions.o

$(test_object) : $(objects)
	$(LD) -o $(test_object) $(objects) -L../src -lroman_calculator -lcheck -lpthread -lrt -lm

test_conversions.o : test_conversions.c ../src/conversions.c 
	$(COMPILE) -c test_conversions.c

.PHONY: check
check: $(test_object)
	./$(test_object)

.PHONY: clean
clean :
	rm -f $(test_object) $(objects)
