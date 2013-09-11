DOXY_EXEC_PATH = C:/Users/mboussai/Desktop/Mohamed/Qt Projects/MARCS
DOXYFILE = C:/Users/mboussai/Desktop/Mohamed/Qt Projects/MARCS/-
DOXYDOCS_PM = C:/Users/mboussai/Desktop/Mohamed/Qt Projects/MARCS/perlmod/DoxyDocs.pm
DOXYSTRUCTURE_PM = C:/Users/mboussai/Desktop/Mohamed/Qt Projects/MARCS/perlmod/DoxyStructure.pm
DOXYRULES = C:/Users/mboussai/Desktop/Mohamed/Qt Projects/MARCS/perlmod/doxyrules.make

.PHONY: clean-perlmod
clean-perlmod::
	rm -f $(DOXYSTRUCTURE_PM) \
	$(DOXYDOCS_PM)

$(DOXYRULES) \
$(DOXYMAKEFILE) \
$(DOXYSTRUCTURE_PM) \
$(DOXYDOCS_PM): \
	$(DOXYFILE)
	cd $(DOXY_EXEC_PATH) ; doxygen "$<"
