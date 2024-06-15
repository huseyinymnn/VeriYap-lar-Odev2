all:derle bagla calistir
derle:	
	    g++ -c -I "./include" ./src/Dugum.cpp -o ./lib/Dugum.o
		g++ -c -I "./include" ./src/AgacDugum.cpp -o ./lib/AgacDugum.o
		g++ -c -I "./include" ./src/Yigin.cpp -o ./lib/Yigin.o
		g++ -c -I "./include" ./src/IkiliAramaAgaci.cpp -o ./lib/IkiliAramaAgaci.o
		g++ -c -I "./include" ./src/Kontrol.cpp -o ./lib/Kontrol.o
		g++ -c -I "./include" ./src/main.cpp -o ./lib/main.o
	    

bagla:
	g++  ./lib/main.o ./lib/Dugum.o ./lib/AgacDugum.o ./lib/Yigin.o ./lib/IkiliAramaAgaci.o ./lib/Kontrol.o -o ./bin/program
	
calistir:
	./bin/program.exe