CXX = g++
CXXFLAGS = -O4 -std=c++14 -W -Wall
LIBFLGAS = -L .. -l griday

all: grid_maker grid_maker_fractional grid2visit grid2props grid2COTA

grid_maker: main_grid_maker.cpp
	$(CXX) $(CXXFLAGS) main_grid_maker.cpp $(LIBFLGAS) -o $(@)

grid_maker_fractional: main_grid_maker_fractional.cpp
	$(CXX) $(CXXFLAGS) main_grid_maker_fractional.cpp $(LIBFLGAS) -o $(@)

grid2visit: main_visit.cpp
	$(CXX) $(CXXFLAGS) main_visit.cpp $(LIBFLGAS) -o $(@)

grid2props: adsorption_properties.cpp
	$(CXX) $(CXXFLAGS) adsorption_properties.cpp $(LIBFLGAS) -o $(@)

grid2COTA: main_cota.cpp
	$(CXX) $(CXXFLAGS) main_cota.cpp $(LIBFLGAS) -o $(@)

clean:
	rm grid_maker && rm grid_maker_fractional && rm grid2visit && rm grid2props && rm grid2COTA
