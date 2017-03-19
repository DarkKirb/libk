CXX=$(TARGET)-g++
CXXFLAGS=-w -Werror -Wno-unused -Wno-unused-variable -Wno-reorder -g -fPIC -std=gnu++14 -fstack-protector-strong -fno-exceptions -fno-rtti -fno-use-cxa-atexit -fdump-class-hierarchy -ffreestanding -nostdlib -Iinclude/ -I../kernel/include -D__EXTERNAL
SRCS=$(shell find . -name '*.cpp')
OBJS=$(addsuffix .o,$(basename $(SRCS)))

libc.a: $(OBJS)
	$(TARGET)-ar rcs $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $^
clean:
	rm -rf $(OBJS) libc.a
