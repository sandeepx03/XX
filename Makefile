CC = g++
CFLAGS =
COPTFLAGS = -O3 -g
LDFLAGS =

default:
    @echo "=================================================="
    @echo "To build your sorting code, use:"
    @echo "  make queue_test               # For enqueue and dequeue"
    @echo "  make dlist_test               # For DLL"
    @echo ""
    @echo "To clean this subdirectory (remove object files"
    @echo "and other junk), use:"
    @echo "  make clean"
    @echo "=================================================="

# Queue driver 
queue_test: queue_test.o
    $(CC) $(COPTFLAGS) -o $@ $^

# DLL driver
dlist_test: dlist_test.o
    $(CC) $(COPTFLAGS) -o $@ $^

%.o: %.cc
    $(CC) $(CFLAGS) $(COPTFLAGS) -o $@ -c $<

clean:
    rm -f core *.o *~ insertion-sort insertion-sort-bisearch mergesort

# eof
