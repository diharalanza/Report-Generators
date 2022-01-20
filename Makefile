final: main.o Control.o ReportGenerator.o FirstReportGenerator.o SecondReportGenerator.o ThirdReportGenerator.o FourthReportGenerator.o FifthReportGenerator.o NGSReport.o View.o
	g++ -o final main.o Control.o ReportGenerator.o FirstReportGenerator.o SecondReportGenerator.o ThirdReportGenerator.o FourthReportGenerator.o FifthReportGenerator.o NGSReport.o View.o

main.o: main.cc Control.h
	g++  -c main.cc

Control.o: Control.cc Control.h ReportGenerator.h View.h Property.h
	g++ -c Control.cc

NGSReport.o: NGSReport.cc NGSReport.h
	g++ -c NGSReport.cc

ReportGenerator.o: ReportGenerator.cc ReportGenerator.h NGSReport.h Property.h
	g++ -c ReportGenerator.cc

FirstReportGenerator.o: FirstReportGenerator.cc ReportGenerator.h
	g++ -c FirstReportGenerator.cc

SecondReportGenerator.o: SecondReportGenerator.cc ReportGenerator.h
	g++ -c SecondReportGenerator.cc

ThirdReportGenerator.o: ThirdReportGenerator.cc ReportGenerator.h
	g++ -c ThirdReportGenerator.cc

FourthReportGenerator.o: FourthReportGenerator.cc ReportGenerator.h
	g++ -c FourthReportGenerator.cc

FifthReportGenerator.o: FifthReportGenerator.cc ReportGenerator.h
	g++ -c FifthReportGenerator.cc

View.o: View.cc View.h
	g++ -c View.cc

clean:
	rm -f *.o final
