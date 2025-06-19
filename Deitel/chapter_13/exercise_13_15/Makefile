progname=ex
utest=utest_$(progname)
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
		
clean:
	rm -rf *.ii *.d *.s *.o sources/*.ii sources/*.d sources/*.s sources/*.o *.output tests/*.output $(BUILDS) $(progname) .gitignore

.PRECIOUS:  $(PREPROCS) $(ASSEMBLES)
.SECONDARY: $(PREPROCS) $(ASSEMBLES)

sinclude  $(DEPENDS)

