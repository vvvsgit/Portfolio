progname=ex
CXX=g++
CXXFLAGS=-Wall -Wextra -Werror -std=c++03 -g3

TEST_INPUTS:=$(wildcard test*.input)
SOURCES:=$(wildcard *.cpp)
PREPROCS:=$(patsubst %.cpp,%.ii,$(SOURCES))
ASSEMBLES:=$(patsubst %.cpp,%.s,$(SOURCES))
OBJS:=$(patsubst %.cpp,%.o,$(SOURCES))
TESTS:=$(patsubst %.input,%,$(TEST_INPUTS))

qa: $(TESTS)

test%: $(progname)
	./$< < $@.input > $@.output || echo "Negative test..."
	diff $@.output $@.expected > /dev/null && echo PASSED || echo FAILED

$(progname): $(OBJS) | .gitignore
	$(CXX) $(CXXFLAGS)    $^ -o $@

%.o: %.s
	$(CXX) $(CXXFLAGS) -c $< -o $@

%.s: %.ii
	$(CXX) $(CXXFLAGS) -S $< -o $@

%.ii: %.cpp
	$(CXX) $(CXXFLAGS) -E $< -o $@

.gitignore:
	echo $(progname) > .gitignore

clean:
	rm -rf *.ii *.s *.o *.output $(progname) .gitignore

.PRECIOUS: $(PREPROCS) $(ASSEMBLES)
.SECONDARY: $(PREPROCS) $(ASSEMBLES)

