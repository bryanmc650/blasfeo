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

include ../Makefile.rule

BLAS_NETLIB = blas-3.8.0
BLAS_DIR = blas

CBLAS_NETLIB = cblas
CBLAS_DIR = cblas


obj_blas: | $(BLAS_DIR)
	@echo "compiling BLAS ..."
	(cd $(BLAS_DIR); $(MAKE) all)


$(BLAS_DIR):
	@echo "downloading BLAS ..."
	wget www.netlib.org/blas/$(BLAS_NETLIB).tgz -O $(BLAS_NETLIB).tgz
	mkdir -p $(BLAS_DIR)
	tar -xzf $(BLAS_NETLIB).tgz -C $(BLAS_DIR) --strip-components 1
	@echo "" >> $(BLAS_DIR)/make.inc
	@echo "#" >> $(BLAS_DIR)/make.inc
	@echo "# BLASFEO's custom flags" >> $(BLAS_DIR)/make.inc
	@echo "#" >> $(BLAS_DIR)/make.inc
	@echo "OPTS = $(CFLAGS) -O3" >> $(BLAS_DIR)/make.inc


obj_cblas: | $(CBLAS_DIR)
	@echo "compiling CBLAS ..."
	(cd $(CBLAS_DIR); $(MAKE) alllib)


$(CBLAS_DIR):
	@echo "downloading CBLAS ..."
	wget www.netlib.org/blas/blast-forum/$(CBLAS_NETLIB).tgz -O $(CBLAS_NETLIB).tgz
	mkdir -p $(CBLAS_DIR)
	tar -xzf $(CBLAS_NETLIB).tgz -C $(CBLAS_DIR) --strip-components 1
	@echo "" >> $(CBLAS_DIR)/Makefile.in
	@echo "#" >> $(CBLAS_DIR)/Makefile.in
	@echo "# BLASFEO's custom flags" >> $(CBLAS_DIR)/Makefile.in
	@echo "#" >> $(CBLAS_DIR)/Makefile.in
	@echo "CFLAGS = $(CFLAGS) -DADD_" >> $(CBLAS_DIR)/Makefile.in
	@echo "FFLAGS = $(CFLAGS)" >> $(CBLAS_DIR)/Makefile.in
	@echo "BLLIB = $(BLAS_DIR)/blas_LINUX.a" >> $(CBLAS_DIR)/Makefile.in


clean:
ifneq ($(wildcard $(BLAS_DIR)), )
	make -C $(BLAS_DIR) clean
endif
#	if [ -d "./$(BLAS_DIR)" ]; then \
#		make -C $(BLAS_DIR) clean; \
#	fi
ifneq ($(wildcard $(CBLAS_DIR)), )
	make -C $(CBLAS_DIR) cleanall
endif


deep_clean:
	rm -rf $(BLAS_DIR)
	rm -rf $(BLAS_NETLIB).tgz
	rm -rf $(CBLAS_DIR)
	rm -rf $(CBLAS_NETLIB).tgz


.PHONY: obj_blas obj_cblas clean deep_clean