TARGET=main
include ../shared/Makefile.shared

CXX_FLAGS += -std=c++11 -O3 -Wall

$(TARGET): $(TARGET).o
	$(CXX) $(CXX_FLAGS) $(TARGET).o -lm $(SNIPER_LDFLAGS) -o $(TARGET)

$(TARGET).o:
	$(CXX) $(CXX_FLAGS) $(SNIPER_CFLAGS) -c $(TARGET).cpp -o $(TARGET).o

run_$(TARGET):
	../../run-sniper -v -n 1 -c gainestown --roi --gdb -- ./$(TARGET) -p 1

clean:
	rm -rf $(SUITE) test/out/* *.db $(TARGET) *.csv sim.* *.log *.out *.png *.o topo.* power.* $(CLEAN_EXTRA)
CLEAN_EXTRA=viz

# move:
# 	rm -rf $(TARGET)/
# 	mkdir $(TARGET)/
# 	mv *.csv *.out $(TARGET)/ 