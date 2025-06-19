progname=ex
utest=utest_$(progname)
slib=lib$(progname).a
dlib= $(progname).so
CXX=g++
CXXFLAGS=-Wall -Wextra -Werror -std=c++03 -I.
BUILDS=builds

ifeq ($(MAKECMDGOALS),)
	BUILD_DIR=$(BUILDS)/debug
else
	BUILD_DIR=$(BUILDS)/$(MAKECMDGOALS)
endif

debug:   CXXFLAGS+=-g3
release: CXXFLAGS+=-g0 -DNDEBUG

SOURCES=main.cpp $(wildcard sources/*.cpp)
DEPENDS=$(patsubst %.cpp,%.d,$(SOURCES))
PREPROCS=$(patsubst %.cpp,%.ii,$(SOURCES))
ASSEMBLES=$(patsubst %.cpp,%.s,$(SOURCES))
OBJS=$(patsubst %.cpp,%.o,$(SOURCES))

UTEST_SOURCES=main_utest.cpp $(wildcard sources/*.cpp)
UTEST_DEPENDS=$(patsubst %.cpp,%.d,$(UTEST_SOURCES))
UTEST_PREPROCS=$(patsubst %.cpp,%.ii,$(UTEST_SOURCES))
UTEST_ASSEMBLES=$(patsubst %.cpp,%.s,$(UTEST_SOURCES))
UTEST_OBJS=$(patsubst %.cpp,%.o,$(UTEST_SOURCES))

LIB_SOURCES=$(wildcard sources/*.cpp)
LIB_DEPENDS=$(patsubst %.cpp,%.d,$(LIB_SOURCES))
LIB_PREPROCS=$(patsubst %.cpp,%.ii,$(LIB_SOURCES))
LIB_ASSEMBLES=$(patsubst %.cpp,%.s,$(LIB_SOURCES))
LIB_OBJS=$(patsubst %.cpp,%.o,$(LIB_SOURCES))

TEST_INPUTS=$(wildcard tests/test*.input)
TESTS=$(patsubst %.input,%,$(TEST_INPUTS))

debug:   $(BUILD_DIR) utest
release: $(BUILD_DIR) qa

utest: $(BUILD_DIR)/$(utest)
	./$<

qa: $(TESTS)

test%: $(BUILD_DIR)/$(progname)
	./$< < $@.input > $@.output
	diff $@.output $@.expected > /dev/null && echo "$@ PASSED" || echo "$@ FAILED"

$(BUILD_DIR)/$(utest): $(UTEST_OBJS) | .gitignore
	$(CXX) $(CXXFLAGS)    $^ -lgtest -lpthread -o $@

$(BUILD_DIR)/$(slib): $(LIB_OBJS) | .gitignore
	ar -crv $@ $^

$(BUILD_DIR)/$(dlib): $(LIB_OBJS) | .gitignore
	$(CXX) $(CXXFLAGS)    $^ --shared -o $@

$(BUILD_DIR)/$(progname): $(OBJS) | .gitignore
	$(CXX) $(CXXFLAGS)    $^ -o $@

%.ii: %.cpp
	$(CXX) $(CXXFLAGS) -E $< -o $@
	$(CXX) $(CXXFLAGS) -MM $< -MT $@ > $(patsubst %.ii,%.d, $@)

%.s: %.ii
	$(CXX) $(CXXFLAGS) -S $< -o $@

%.o: %.s
	$(CXX) $(CXXFLAGS) -c $< -o $@

.gitignore:
	echo $(progname) > .gitignore

$(BUILD_DIR):
	mkdir -p $@
		
install:
	cp headers/IntVector.hpp /usr/local/include
	#cp builds/debug/$(slib) /usr/local/lib
	cp builds/debug/$(dlib) /usr/local/lib

clean:
	rm -rf *.ii *.d *.s *.o sources/*.ii sources/*.d sources/*.s sources/*.o *.output tests/*.output $(BUILDS) $(progname) .gitignore

.PRECIOUS:  $(PREPROCS) $(ASSEMBLES)
.SECONDARY: $(PREPROCS) $(ASSEMBLES)

sinclude  $(DEPENDS)

