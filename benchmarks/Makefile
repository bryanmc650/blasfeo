###################################################################################################
#                                                                                                 #
# This file is part of BLASFEO.                                                                   #
#                                                                                                 #
# BLASFEO -- BLAS For Embedded Optimization.                                                      #
# Copyright (C) 2016-2018 by Gianluca Frison.                                                     #
# Developed at IMTEK (University of Freiburg) under the supervision of Moritz Diehl.              #
# All rights reserved.                                                                            #
#                                                                                                 #
# This program is free software: you can redistribute it and/or modify                            #
# it under the terms of the GNU General Public License as published by                            #
# the Free Software Foundation, either version 3 of the License, or                               #
# (at your option) any later version                                                              #.
#                                                                                                 #
# This program is distributed in the hope that it will be useful,                                 #
# but WITHOUT ANY WARRANTY; without even the implied warranty of                                  #
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the                                   #
# GNU General Public License for more details.                                                    #
#                                                                                                 #
# You should have received a copy of the GNU General Public License                               #
# along with this program.  If not, see <https://www.gnu.org/licenses/>.                          #
#                                                                                                 #
# The authors designate this particular file as subject to the "Classpath" exception              #
# as provided by the authors in the LICENSE file that accompained this code.                      #
#                                                                                                 #
# Author: Gianluca Frison, gianluca.frison (at) imtek.uni-freiburg.de                             #
#                                                                                                 #
###################################################################################################

# ----------- Include
include ../Makefile.rule

LIBS =

LIBS += $(BINARY_DIR)/libblasfeo.a

#include ../Makefile.external_blas
LIBS += $(LIBS_EXTERNAL_BLAS)

LIBS += -lm

#ifeq ($(EXTERNAL_BLAS), 0)
#get_refblas:
#	$(info )
#	$(info ERROR EXTERNAL_BLAS is not set or invalid)
#	$(info )
#	$(error .)
#else
get_refblas:
	@echo Using EXTERNAL_BLAS=$(EXTERNAL_BLAS)
#endif

ifdef GHZ_MAX
CFLAGS += -DGHZ_MAX=$(GHZ_MAX)
get_cpu_freq:
	@echo Using GHZ_MAX=$(GHZ_MAX) from command line option
else
ifeq (,$(wildcard ./cpu_freq.h))
get_cpu_freq:
	$(info )
	$(info ERROR GHZ_MAX is not set, create cpu_freq.h or specify GHZ_MAX Makefile option)
	$(info )
	$(error .)
else
get_cpu_freq:
	@echo Using GHZ_MAX from cpu_freq.h
endif
endif

# all benchmarks
ONE_OBJS = benchmark_d_blasfeo_api.o
#ONE_OBJS = benchmark_s_blasfeo_api.o
#ONE_OBJS = benchmark_d_blas_api.o
#ONE_OBJS = benchmark_bandwidth.o

%.o: %.c
	# build obj
	$(CC) $(CFLAGS) -c $< -o $(BINARY_DIR)/$@
	$(CC) $(CFLAGS) $(BINARY_DIR)/$@ -o $(BINARY_DIR)/$@.out $(LIBS)

# ----------- Targets

bin_dir:
	# create bin folder if not existent
	mkdir -p $(BINARY_DIR)/
	mkdir -p $(BINARY_DIR)/BLASFEO_API/
ifeq ($(BLAS_API), 1)
	mkdir -p $(BINARY_DIR)/BLAS_API/
endif

common: get_refblas get_cpu_freq bin_dir
	cp ../lib/libblasfeo.a ./$(BINARY_DIR)
#	echo $(OBJS)

.DEFAULT_GOAL := build
.PHONY: build

build: common $(ONE_OBJS)

run:
	./$(BINARY_DIR)/$(ONE_OBJS).out


clean:
	rm -rf ./*.o
	rm -rf ./*.out
	rm -rf ./$(BINARY_DIR)/BLASFEO_API/*.o
	rm -rf ./$(BINARY_DIR)/BLASFEO_API/*.out
	rm -rf ./$(BINARY_DIR)/BLAS_API/*.o
	rm -rf ./$(BINARY_DIR)/BLAS_API/*.out
	rm -rf ./$(BINARY_DIR)/libblasfeo.a

deep_clean: clean
	rm -rf ./figures/
	rm -rf ./build/



# figures

figures_benchmark_one:
	cp figures_benchmark_one.m ./build/
	cd ./build/ ; octave-cli figures_benchmark_one.m



# benchmark BLASFEO API
include Makefile.blasfeo_api



# benchmark BLAS API
include Makefile.blas_api
