##**********生成可执行文件**************
main:main.cpp HanderLogs.cpp create_menu.cpp ip_to_int.cpp
	g++ main.cpp HanderLogs.cpp create_menu.cpp ip_to_int.cpp -o main
IPLocator.exe:IPLocator.cpp
	g++ IPLocator.cpp -o IPLocator.exe
HanderLogs.exe:HanderLogs.cpp
	g++ HanderLogs.cpp -o HanderLogs.exe
ip_to_int.exe:ip_to_int.cpp
	g++ ip_to_int.cpp -o ip_to_int.exe
create_menu.exe:create_menu.cpp
	g++ create_menu.cpp -o create_menu.exe

#*************创建静态库************
libmenu.a:create_menu.cpp
	ar -r libmenu.a create_menu.cpp
libIPLocator.a:IPLocator.cpp
	ar -r libIPLocator.a IPLocator.cpp
#*************创建动态库************
libgetLogs.so:HanderLogs.cpp
	g++ HanderLogs.cpp -fPIC -shared -o libgetLogs.so
libIPint.so:ip_to_int.cpp
	g++ ip_to_int.cpp -fPIC -shared -o libIPint.so
#*************保存库***************
move:libgetLogs.so libIPint.so
	mv -u libgetLogs.so libIPint.so lib
install:libmenu.a libIPLocator.a
	sudo cp libmenu.a libIPLocator.a /usr/lib
#*************连接****************
link_static:libmenu.a libIPLocator.a main.cpp
	g++ -o binary-static main.cpp -lmenu -lIPLocator -static
link_auto:libgetLogs.so libIPint.so main.cpp
	g++ -o binary-dynamic main.cpp -L./ -lgetLogs -lIPint
#*************清除所有文件*********
clean:
	rm main *.exe *.a *.so lib/*