#include "MapCreator.h"
using namespace std;
using namespace pg;

MapCreator::MapCreator ( std::string input, std::string output ) :
	input ( input ), output ( output )
{
	readOutdated();
}

MapCreator::~MapCreator()
{
	//dtor
}
void MapCreator::readOutdated() {
	ifstream file ( input, ios::binary | ios::ate );
	int size = file.tellg();
	file.seekg ( 0, ios::beg );
	//reading mainFile
	if ( file.is_open() ) {
		while ( size >= 0 ) {
			dataBlock block = dataBlock();

			int namesize = 0;
			file.read ( ( char* ) &namesize, sizeof ( int ) );
			size = size - sizeof ( int ) ;
			char temp[namesize+1];
			file.read ( ( char* ) temp, namesize );
			temp[namesize] = '\0';
			block.name = temp;

			size -= namesize;


			int coordamount = 0;
			file.read ( ( char* ) &coordamount, sizeof ( int ) );
			size -= sizeof ( int );

			for ( int i = 0; i < coordamount; i++ ) {

				float x = 0;
				float y = 0;

				file.read ( ( char* ) &x, sizeof ( float ) );
				file.read ( ( char* ) &y, sizeof ( float ) );
				pg::Coord point ( x, y );
				size -= sizeof ( float );
				size -= sizeof ( float );
				block.poly.push_back ( point );
			}
			data.push_back ( block );
		}
	} else {
		std::cout << "fuu" << std::endl;
	}

	ifstream progressFile ( "mapas.sav", ios::binary | ios::ate );
	size = progressFile.tellg();
	progressFile.seekg ( 0, ios::beg );
	cont = 0;
	if ( size == 0 || !progressFile.is_open() ) {
		cout << "starting Now" << endl;
	} else {

		progressFile.read ( ( char* ) &cont, sizeof ( int ) );

	}

	if ( data.size() > cont ) {
		std::cout << "continuing at " << data[cont].name << std::endl;

	}



}
void MapCreator::setCenter ( pg::MouseEvent e ) {
    std::cout<< cont <<std::endl;
    std::cout<< data.size() <<std::endl;
    if(cont>=data.size()){
        cout<<"done";
        done=true;
	}
    if(done)return;
	data[cont].center = e.coord;
	saveOutdated();
	cont++;
	std::cout << "next is " << data[cont].name << std::endl;
    ofstream file2 ( "mapas.sav", ios::binary );
	if ( file2.is_open() ) {
		file2.write ( ( char* ) &cont, sizeof ( char ) );
	}








}
template<class A>
static void writeToFile ( ofstream* file, A& a ) {
	try {
		file->write ( ( char* ) &a, sizeof ( a ) );
	} catch ( std::ios_base::failure e ) {
		std::cout << "unable to write to file" << std::endl;
	}
}

void MapCreator::saveOutdated() {
	//doesnt save neighbors
	ofstream file ( output, ios::binary | ios::app );
	if ( file.is_open() ) {
		int temp = data.size();
		writeToFile ( &file, temp );

     dataBlock x=data[cont];

			//printing name
			short length = x.name.length();
			writeToFile ( &file, length );
			for ( int i = 0; i < length; i++ ) {
				writeToFile ( &file, x.name[i] );
			}


			//printing polygon
			short polyNumb = x.poly.size();
			writeToFile ( &file, polyNumb );

			for ( int i = 0; i < polyNumb; i++ ) {
				float cx = x.poly[i].x;
				float cy = x.poly[i].y;
				writeToFile ( &file, cx );
				writeToFile ( &file, cy );
			}

			//printing neighbors
			short size = x.neighbors.size();
            writeToFile(&file,size);

			for ( int i = 0; i < size; i++ ) {
			     string neigh_name=x.neighbors[i];

			     short length=neigh_name.length();
			     writeToFile(&file,length);
			     for (int j=0;j<length;j++){
			         writeToFile(&file, neigh_name[j] );

			     }






			}




	}else{
	std::cout<< "fooo" <<std::endl;

	}
}
void MapCreator::notify ( pg::MouseEvent e ) {
    if(e.click!=MouseEvent::LEFT_UP)return;
	setCenter ( e );
}
