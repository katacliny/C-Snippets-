 /**************************************
* NOMBRE: #Manuel Alejandro#
* PRIMER APELLIDO: #Garrido#
* SEGUNDO APELLIDO: #Gongora#
***************************************/

#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include <time.h>
#include <stdlib.h>


typedef char StringArray[500];
typedef StringArray WordsList[100];
typedef int IntegerArray[12];
typedef int IntegerArrayWeek[7];
typedef int IntegerArrayMonth[31];


typedef struct City{
      StringArray cityName;
      int postalCode;

  };

typedef struct Connection{
      City cityconnection;
      int distance;
  };

typedef Connection ConnectionList[200];

typedef struct RouteCalendar{
        int day;
        int year;
        int mont;
        int hour;
  };

typedef City CityList [200];

typedef struct CityConnections{
      City cityconnection;
      Connection ConnectionList[20];
      int len_connection;
      bool find;
      int counter;
      CityList  visitadas;
      City start;
      City end;
      RouteCalendar calendar[20];
  };

typedef CityConnections AllConections[200];

typedef struct CityToCity{
      City start;
      City end;
  };

int treepL = 0;
int stop = 0;

typedef CityToCity Journeys [200];

RouteCalendar DefaultCalendar = {-1, -1, -1, -1};
Journeys  AllJourneys ;

AllConections ManualJourneys ;
int lastManual = 0;
AllConections ConnectionsList;

ConnectionList path;
CityList  visitadas;
CityList  allCities;


StringArray bus_techo =   "    ______________________\n";
StringArray bus_section1 ="   |,----.,----.,----.,--.\ \n";
StringArray bus_section2 ="   ||    ||    ||    ||   \\ \n";
StringArray bus_section3 ="   |`----'`----'|----||----\`. \n";
StringArray bus_section4 ="   [";
 StringArray bus_section10 ="|   -||- __|(| \n";
StringArray bus_section5 ="   [  ,--.      |____||.--.  | \n";
StringArray bus_section6 ="   =-(( `))-----------(( `))== \n";
StringArray bus_section7 ="      `--'             `--' \n";
StringArray bus_section8 ="\n";
StringArray bus_section9 ="------------------------------------------------ Oviedo Bus Station \n";

StringArray text1 =" ______                    _   _ _       _        _  \n";
StringArray text2 =" | ___ \                  | | | (_)     (_)      | | \n";
StringArray text3 =" | |_/ /_   _  ___ _ __   | | | |_  __ _ _  ___  | | \n";
StringArray text4 =" | ___ \ | | |/ _ \ '_ \  | | | | |/ _` | |/ _ \ | | \n";
StringArray text5 =" | |_/ / |_| |  __/ | | | \ \_/ / | (_| | |  __/ |_| \n";
StringArray text6 =" \____/ \__,_|\___|_| |_|  \___/|_|\__,_| |\___| (_) \n";
StringArray text7 ="                                      _/ |           \n";
StringArray text8 ="                                     |__/            \n";


void draw_buen_viaje(){
    printf(text1);
    printf(text2);
    printf(text3);
    printf(text4);
    printf(text5);
    printf(text6);
    printf(text7);
    printf(text8);
  }


void draw_bus(City start, City end){
    StringArray target;
    StringArray target2;
    strncpy(target, start.cityName, 3);
    strncpy(target2, end.cityName, 3);
    printf(bus_techo);
    printf(bus_section1);
    printf(bus_section2);
    printf(bus_section3);
    printf(bus_section4);
    printf("   ");
    printf(target);
    printf("-");
    printf(target2);
    printf("  ");
    printf(bus_section10);
    printf(bus_section5);
    printf(bus_section6);
    printf(bus_section7);
    printf(bus_section8);
    printf(bus_section9);
  }


//Interior

City Default = {"D", 0};

City Bulnes = {"Bulnes", 33009};
City Sotres = {"Sotres", 33009};
City Tielve = {"Tielve", 33009};
City Arenos = {"Arenos", 33009};
City Carrena = {"Carrena", 33009};
City Arangas = {"Arangas", 33009};
City Rozagas = {"Rozagas", 33009};
City Ruenes = {"Ruenes", 33009};
City Avin = {"Avin", 33009};
City La_Robellada = {"La_Robellada", 33009};

//Costas

City Gijon = {"Gijon", 33009};
City Salinas = {"Salinas", 33009};
City Aviles = {"Aviles", 33009};
City Luarca = {"Luarca", 33009};
City Cudillero = {"Cudillero", 33009};
City Muros_del_Nalon = {"Muros_del_Nalon", 33009};
City San_Juan_de_la_Arena = {"Sanjuan_de_la_Arena", 33009};
City Ribadesella = {"Ribadesella", 33009};
City Soto_del_Barco = {"Soto_del_Barco", 33009};
City Rellayo = {"Rellayo", 33009};
City Aronces = {"Aronces", 33009};

//Cuenca Minera

City Oviedo = {"Oviedo", 33009};
City Olloniego = {"Olloniego", 33009};
City El_Calello = {"El_Calello", 33009};
City Las_segadas = {"Las_segadas", 33009};
City Tudela_Veguim = {"Tudela_Veguim", 33009};
City Soto_de_Rey = {"Soto_de_Rey", 33009};
City Santa_Eulalia = {"Santa_Eulalia", 33009};
City Pena_Rubia = {"Pena_Rubia", 33009};

Connection gc(City connection, int distance){
    Connection response;
    response.cityconnection = connection;
    response.distance = distance;
    return response;
  }

CityToCity getCityToCityJournie(City start, City end){
    CityToCity response;

    response.start = start;
    response.end = end;
    return response;
  }

CityConnections gcc(City cityconn){
    CityConnections response;
    response.cityconnection = cityconn;
    return response;
  }
int lastCity = 27;

void defineAllCities(){

    allCities[0] = Oviedo;
    allCities[1] = Bulnes;
    allCities[2] = Sotres;
    allCities[3] = Tielve;
    allCities[4] = Arenos;
    allCities[5] = Carrena;
    allCities[6] = Arangas;
    allCities[7] = Rozagas;
    allCities[8] = Ruenes;
    allCities[9] = Avin;
    allCities[10] = La_Robellada;
    allCities[11] = Salinas;
    allCities[12] = Aviles;
    allCities[13] = Luarca;
    allCities[14] = Cudillero;
    allCities[15] = Muros_del_Nalon;
    allCities[16] = San_Juan_de_la_Arena;
    allCities[17] = Ribadesella;
    allCities[18] = Soto_del_Barco;
    allCities[19] = Rellayo;
    allCities[20] = Aronces;
    allCities[21] = Olloniego;
    allCities[22] = El_Calello;
    allCities[23] = Las_segadas;
    allCities[24] = Tudela_Veguim;
    allCities[25] = Soto_de_Rey;
    allCities[26] = Santa_Eulalia;
    allCities[27] = Pena_Rubia;

  }

int lastConection = 12;

void DefineDefaultCitiesConnections(){
    CityConnections OviedoConnections = gcc(Oviedo);
    CityConnections GijonConnections = gcc(Gijon);
    CityConnections AvilesConnections = gcc(Aviles);
    CityConnections CalelloConnections = gcc(El_Calello);
    CityConnections SegadasConnections = gcc(Las_segadas);
    CityConnections SotodeReyConnections = gcc(Soto_de_Rey);
    CityConnections SantaEulaliaConnections = gcc(Santa_Eulalia);
    CityConnections TudelaVeguimConnections = gcc(Tudela_Veguim);
    CityConnections SalinasConnection = gcc(Salinas);
    CityConnections LuarcaConnection = gcc(Luarca);
    CityConnections SotoDelBarcoConnection = gcc(Soto_del_Barco);
    CityConnections CudilleroConnection = gcc(Cudillero);

    OviedoConnections.ConnectionList[0] = gc(Gijon, 5);
    OviedoConnections.ConnectionList[1] = gc(El_Calello, 5);
    OviedoConnections.ConnectionList[3] = gc(Bulnes, 5);
    OviedoConnections.ConnectionList[4] = gc(Sotres, 5);
    OviedoConnections.ConnectionList[5] = gc(Tielve, 5);
    OviedoConnections.ConnectionList[6] = gc(Arenos, 5);
    OviedoConnections.ConnectionList[7] = gc(Carrena, 5);
    OviedoConnections.ConnectionList[8] = gc(Arangas, 5);
    OviedoConnections.ConnectionList[9] = gc(Rozagas, 5);
    OviedoConnections.ConnectionList[10] = gc(Ruenes, 5);
    OviedoConnections.ConnectionList[11] = gc(Avin, 5);
    OviedoConnections.ConnectionList[12] = gc(La_Robellada, 5);

    GijonConnections.ConnectionList[0] = gc(Oviedo, 5);
    GijonConnections.ConnectionList[1] = gc(Ribadesella, 5);
    GijonConnections.ConnectionList[2] = gc(Aviles, 5);

    AvilesConnections.ConnectionList[0] = gc(Gijon, 5);
    AvilesConnections.ConnectionList[1] = gc(Oviedo, 5);
    AvilesConnections.ConnectionList[2] = gc(Salinas, 5);

    CalelloConnections.ConnectionList[0] = gc(Oviedo, 5);
    CalelloConnections.ConnectionList[1] = gc(Las_segadas, 5);

    SegadasConnections.ConnectionList[0] = gc(El_Calello, 5);
    SegadasConnections.ConnectionList[1] = gc(Soto_de_Rey, 5);

    SotodeReyConnections.ConnectionList[0] = gc(Las_segadas, 5);
    SotodeReyConnections.ConnectionList[1] = gc(Santa_Eulalia, 5);

    SantaEulaliaConnections.ConnectionList[0] = gc(Soto_de_Rey, 5);
    SantaEulaliaConnections.ConnectionList[1] = gc(Tudela_Veguim, 5);

    TudelaVeguimConnections.ConnectionList[0] = gc(Santa_Eulalia, 5);
    TudelaVeguimConnections.ConnectionList[1] = gc(Pena_Rubia, 5);


    SalinasConnection.ConnectionList[0] = gc(Oviedo, 5);
    SalinasConnection.ConnectionList[1] = gc(Cudillero, 15);

    CudilleroConnection.ConnectionList[0] = gc(Salinas, 15);
    CudilleroConnection.ConnectionList[1] = gc(Luarca, 5);

    LuarcaConnection.ConnectionList[0] = gc(Cudillero, 5);
    LuarcaConnection.ConnectionList[1] = gc(Soto_del_Barco, 5);

    SotoDelBarcoConnection.ConnectionList[0] = gc(Luarca, 5);
    SotoDelBarcoConnection.ConnectionList[1] = gc(Muros_del_Nalon, 5);

    ConnectionsList[0] = OviedoConnections;
    ConnectionsList[1] = GijonConnections;
    ConnectionsList[2] = CalelloConnections;
    ConnectionsList[3] = SegadasConnections;
    ConnectionsList[4] = SotodeReyConnections;
    ConnectionsList[5] = SantaEulaliaConnections;
    ConnectionsList[6] = TudelaVeguimConnections;
    ConnectionsList[7] = AvilesConnections;
    ConnectionsList[8] = SalinasConnection;
    ConnectionsList[9] = CudilleroConnection;
    ConnectionsList[10] = LuarcaConnection;
    ConnectionsList[11] = SotoDelBarcoConnection;

  }


void DefineDefaultConections(){
    DefineDefaultCitiesConnections();
  }


CityConnections  findRoute(City partida, City destino, int counter){
    CityConnections finalRoute;

    CityConnections result;
    bool is = false;
    finalRoute.find = false;
    for(int i = 0; i<200; i++){
          if(strlen(ConnectionsList[i].cityconnection.cityName) > 0 && strcmp(ConnectionsList[i].cityconnection.cityName, partida.cityName) == 0 ){

              for(int x = 0; x<20; x++){
                is = false;
                if(strlen(ConnectionsList[i].ConnectionList[x].cityconnection.cityName) > 0){


                  for(int y = 0; y<200; y++){
                          if(strlen(visitadas[y].cityName) > 1 && strcmp(visitadas[y].cityName, ConnectionsList[i].ConnectionList[x].cityconnection.cityName) == 0){
                            is  = true;
                          }
                  }
                  if(strcmp(ConnectionsList[i].ConnectionList[x].cityconnection.cityName, destino.cityName) == 0){
                        counter ++;
                        finalRoute.ConnectionList[counter] = ConnectionsList[i].ConnectionList[x];
                        path[counter] = ConnectionsList[i].ConnectionList[x];
                        finalRoute.len_connection = counter;
                        finalRoute.find = true;
                        finalRoute.start = partida;
                        finalRoute.end = destino;
                        return finalRoute;
                  }
                  if(!is){
                      counter ++;
                      visitadas[counter] = ConnectionsList[i].ConnectionList[x].cityconnection;
                      finalRoute.visitadas[counter] = ConnectionsList[i].ConnectionList[x].cityconnection;
                      result = findRoute(ConnectionsList[i].ConnectionList[x].cityconnection, destino, counter);
                      for(int c = counter; c<(result.counter - counter); c++){
                          visitadas[c] = result.visitadas[c];
                      }
                      if(result.find){

                          finalRoute.find = true;
                          finalRoute.ConnectionList[counter] = ConnectionsList[i].ConnectionList[x];
                          path[counter] = ConnectionsList[i].ConnectionList[x];
                          finalRoute.start = partida;
                          finalRoute.end = destino;
                          return finalRoute;
                      }
                      counter = counter + (result.counter - counter);
                    }
                  }
                }
              }
            }
    visitadas[counter] = partida;
    finalRoute.visitadas[counter] = partida;
    finalRoute.counter = counter;
    finalRoute.start = partida;
    finalRoute.end = destino;
    return finalRoute;
  }


void DefineDefaultJourneys (){

    AllJourneys [0] = getCityToCityJournie(Oviedo, Gijon);
    AllJourneys [1] = getCityToCityJournie(Oviedo, Aviles);
    AllJourneys [2] = getCityToCityJournie(Oviedo, Soto_de_Rey);
    AllJourneys [3] = getCityToCityJournie(Oviedo, Santa_Eulalia);
    AllJourneys [4] = getCityToCityJournie(Oviedo, Salinas);
    AllJourneys [5] = getCityToCityJournie(Oviedo, Ribadesella);
    AllJourneys [6] = getCityToCityJournie(Oviedo, Cudillero);
    AllJourneys [7] = getCityToCityJournie(Oviedo, Luarca);
    AllJourneys [8] = getCityToCityJournie(Oviedo, Tudela_Veguim);
    AllJourneys [9] = getCityToCityJournie(Oviedo, Las_segadas);
    AllJourneys [10] = getCityToCityJournie(Oviedo, Bulnes);
    AllJourneys [11] = getCityToCityJournie(Oviedo, Sotres);
    AllJourneys [12] = getCityToCityJournie(Oviedo, Tielve);
    AllJourneys [13] = getCityToCityJournie(Oviedo, Arenos);
    AllJourneys [14] = getCityToCityJournie(Oviedo, Carrena);
    AllJourneys [15] = getCityToCityJournie(Oviedo, Arangas);
    AllJourneys [16] = getCityToCityJournie(Oviedo, Rozagas);
    AllJourneys [17] = getCityToCityJournie(Oviedo, Ruenes);
    AllJourneys [18] = getCityToCityJournie(Oviedo, Avin);
    AllJourneys [19] = getCityToCityJournie(Oviedo, La_Robellada);
    AllJourneys [20] = getCityToCityJournie(Oviedo, El_Calello);

  }


void MakeRute(City start, City end){
    CityConnections rute;
    treepL = 0;
    stop = 0;
    for(int i = 0; i<200; i++){ visitadas[i] = Default; path[i].cityconnection = Default; }
    visitadas[0] = start;
    rute = findRoute(start, end, 0);
    draw_bus(rute.start, rute.end);
    printf("Importante: Las rutas Automaticas se efectian diariamente.");
    printf("\n");
    printf("Partida: ");
    printf(start.cityName);
    printf("\n");
    printf("Destino: ");
    printf(end.cityName);
    printf("\n");
    printf("El Bus efectua paradas en:");
    for(int x = 0; x < 200; x++){
      if(strlen(path[x].cityconnection.cityName) > 1){
          stop ++;
          printf("\n");
          printf("%d - ", stop);
          printf(path[x].cityconnection.cityName);
          treepL = treepL + path[x].distance;
          printf("\n");
        }
    };
    printf("\n");
    printf("La distancia es:");
    printf("  ");
    printf("%d km", treepL);
    printf("\n");
    printf("El precio final es:");
    printf("  ");
    printf("%.2f $", treepL * 0.2);
    printf("\n");
    printf("BUEN VIAJE!!");
    printf("\n");
  }

void MakeRutemanualy(CityConnections rute){

    printf("Partida: ");
    printf(rute.start.cityName);
    printf("\n");
    printf("Destino: ");
    printf(rute.end.cityName);
    printf("\n");
    printf("El Bus efectua paradas en:");
    for(int x = 0; x < 200; x++){
      if(strlen(rute.ConnectionList[x].cityconnection.cityName) > 1){
          stop ++;
          printf("\n");
          printf("%d - ", stop);
          printf(rute.ConnectionList[x].cityconnection.cityName);
          treepL = treepL + rute.ConnectionList[x].distance;
          printf("\n");
        }
    };
    printf("\n");
    printf("La distancia es:");
    printf("  ");
    printf("%d km", treepL);
    printf("\n");
    printf("En las fechas:");
    printf("  ");
    for(int x = 0; x < 20; x++){
      if(rute.calendar[x].day > 0){
        printf("\n");
        printf("El dia %d del mes %d del año %d a la hora %d", rute.calendar[x].day, rute.calendar[x].mont, rute.calendar[x].year, rute.calendar[x].hour);
        printf("\n");
      }
    }
    printf("\n");
    printf("\n");
  }

void MakeRutemanualyFinal(CityConnections rute){

    draw_bus(rute.start, rute.end);
    printf("Partida: ");
    printf(rute.start.cityName);
    printf("\n");
    printf("Destino: ");
    printf(rute.end.cityName);
    printf("\n");
    printf("El Bus efectua paradas en:");
    for(int x = 0; x < 200; x++){
      if(strlen(rute.ConnectionList[x].cityconnection.cityName) > 1){
          stop ++;
          printf("\n");
          printf("%d - ", stop);
          printf(rute.ConnectionList[x].cityconnection.cityName);
          treepL = treepL + rute.ConnectionList[x].distance;
          printf("\n");
        }
    };
    printf("\n");
    printf("La distancia es:");
    printf("  ");
    printf("%d km", treepL);
    printf("\n");
    printf("El precio final es:");
    printf("  ");
    printf("%.2f $", treepL * 0.2);
    printf("\n");
    printf("BUEN VIAJE!!");
    printf("\n");
  }

void ShowAllJourneys (){


    for(int i = 0; i<200; i++){
        if(strlen(AllJourneys [i].start.cityName) > 1){
              MakeRute(AllJourneys [i].start, AllJourneys [i].end);

          }
      }

  }

void VisualiceRouteAutomaticaly(){
    int option;
    system("cls");
    printf("\n");
    printf("Rutas Automaticas Activas.");
    for(int i = 0; i<200; i++){
      if(strlen(AllJourneys [i].start.cityName) > 1){
            printf("\n");
            printf("%d   ", i);
            printf("Desde: ");
            printf(AllJourneys [i].start.cityName);
            printf("    ");
            printf("Hasta: ");
            printf(AllJourneys [i].end.cityName);

        }
    }
    printf("\n");
    printf("Teclear el numero de a lruta que desea visualizar?");
    printf("\n");
    printf("\n");
    scanf("%d", &option);
    system("cls");
    MakeRute(AllJourneys [option].start, AllJourneys [option].end);
    printf("Teclear cualquier numero para continuar");
    printf("\n");
    scanf("%d", &option);
  }

void VisualiceRouteManual(){
    int option;
    system("cls");
    printf("\n");
    printf("Rutas Automaticas Activas.");
    for(int i = 0; i<200; i++){
      if(strlen(ManualJourneys [i].start.cityName) > 1){
            printf("\n");
            printf("%d   ", i);
            printf("Desde: ");
            printf(ManualJourneys [i].start.cityName);
            printf("    ");
            printf("Hasta: ");
            printf(ManualJourneys [i].end.cityName);

        }
    }
    printf("\n");
    printf("Teclear el numero de la ruta que desea visualizar?");
    printf("\n");
    printf("\n");
    scanf("%d", &option);
    system("cls");
    MakeRutemanualyFinal(ManualJourneys [option]);
    printf("Teclear cualquier numero para continuar");
    printf("\n");
    scanf("%d", &option);
  }

void VisualiceRoute(){

    int option;
    system("cls");
    printf("\n");
    printf("    Ver Rutas Automaticas:     (Pulse 1)");
    printf("\n");
    printf("    Ver Rutas Manuales:        (Pulse 2)");
    printf("\n");
    printf("    Volver:                    (Pulse 3)");
    printf("\n");
    printf("\n");
    scanf("%d", &option);
    switch(option){

        case 1:
          system("cls");
          VisualiceRouteAutomaticaly();
          break;

        case 2:
          system("cls");
          VisualiceRouteManual();
          break;

        case 3:
          break;

      }

  }

int lasStep = 0;

CityConnections addStepsManualy(CityConnections newRoute){
    int option;
    system("cls");
    printf("\n");
    printf("\n");
    printf("Lista de ciudades actualmente en el sistema.");
    printf("\n");
    for(int i = 0; i<200; i++){
      if(strlen(allCities[i].cityName) > 1){
            printf("\n");
            printf("%d   ", i);
            printf(allCities[i].cityName);
        }
    }
    printf("\n");
    printf("Teclear el numero de la ciudad de parada.");
    printf("\n");
    scanf("%d", &option);
    newRoute.ConnectionList[lasStep] = gc(allCities[option], 5);
    lasStep++;
    printf("\n");
    printf("Quiere añadir otra parada ?  Pulse(1)");
    printf("\n");
    printf("Quiere Continuar ?           Pulse(2)");
    printf("\n");
    scanf("%d", &option);

    switch(option){

        case 1:
          system("cls");
          newRoute = addStepsManualy(newRoute);
          break;
      }

    return newRoute;
  }

void CreateRouteMannual(){

    int option;
    int day;
    int year;
    int mont;
    int hour;
    CityConnections newRoute;
    for(int x = 0; x < 200; x++){
      newRoute.ConnectionList[x].cityconnection = Default;
    };
    for(int x = 0; x < 20; x++){
      newRoute.calendar[x] = DefaultCalendar;
    };

    system("cls");
    printf("\n");
    printf("\n");
    printf("Lista de ciudades actualmente en el sistema.");
    printf("\n");
    for(int i = 0; i<200; i++){
      if(strlen(allCities[i].cityName) > 1){
            printf("\n");
            printf("%d   ", i);
            printf(allCities[i].cityName);
        }
    }
    printf("\n");
    printf("Teclear el numero de la ciudad de destino.");
    printf("\n");
    scanf("%d", &option);
    newRoute.start = Oviedo;
    newRoute.end = allCities[option];
    lasStep = 0;
    newRoute = addStepsManualy(newRoute);
    ManualJourneys [lastManual] = newRoute;
    lastManual++;


  }

void saveRouteAutomaticaly(City to){

    bool exist;
    int option;
    int counter = 0;
    exist = false;
    system("cls");
    printf("\n");
    printf("Estamos procesando su peticion.");
    printf("\n");
    for(int i = 0; i<200; i++){
      if(strlen(AllJourneys [i].start.cityName) > 1){
            counter++;
            if(strcmp(to.cityName, AllJourneys [i].end.cityName) == 0){
                exist = true;
            }
        }
    }
    if(!exist){

        AllJourneys [counter] = getCityToCityJournie(Oviedo, to);

      }

    else{

         printf("\n");
         printf("El viaje ya existe.");
      }

    printf("\n");
    printf("Teclear cualquier numero para volver.");
    printf("\n");
    scanf("%d", &option);


  }

void CreateRouteAutomaticaly(){

    int option;
    system("cls");
    printf("\n");
    printf("Lista de ciudades actualmente en el sistema.");
    printf("\n");
    for(int i = 0; i<200; i++){
      if(strlen(allCities[i].cityName) > 1){
            printf("\n");
            printf("%d   ", i);
            printf(allCities[i].cityName);
        }
    }
    printf("\n");
    printf("Teclear el numero de la ciudad a la que quiere ir.");
    printf("\n");
    scanf("%d", &option);
    saveRouteAutomaticaly(allCities[option]);

  }

void CreateRoute(){
    int option;
    system("cls");
    printf("\n");
    printf("Puede crear una ruta manualmente o dejar que el sistema lo haga por usted.");
    printf("\n");
    printf("    Crear ruta Manualmente:     (Pulse 1)");
    printf("\n");
    printf("    Crear ruta Automaticamente: (Pulse 2)");
    printf("\n");
    printf("    Volver:                     (Pulse 3)");
    printf("\n");
    printf("\n");
    scanf("%d", &option);
    switch(option){

        case 1:
          system("cls");
          CreateRouteMannual();
          CreateRoute();
          break;

        case 2:
          system("cls");
          CreateRouteAutomaticaly();
          CreateRoute();
          break;

        case 3:
          break;

      }
  }

void EditRoute(){
    int option;
    system("cls");
    printf("\n");
    printf("Gestion de Rutas");
    printf("\n");
    printf("    Crear ruta:     (Pulse 1)");
    printf("\n");
    printf("    Volver:         (Pulse 3)");
    printf("\n");
    printf("Teclear una opcion valida (1|2|3)?");
    printf("\n");
    scanf("%d", &option);
    switch(option){

        case 1:
          system("cls");
          CreateRoute();
          EditRoute();
          break;

        case 3:
          break;

      }


  }

int dayofweek(int d, int m, int y)
{
    IntegerArray t = { 0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4 };
    y = y - (m < 3);
    return ( y + y/4 - y/100 + y/400 + t[m-1] + d) % 7;
}



void drawCalendar(int m, int ye, IntegerArrayMonth days){

  int monthL = 0;
  bool f = false;
  bool is = false;
  IntegerArrayWeek weekdays = {0,1,2,3,4,5,6};
  int weekCounter = 0;
  switch(m){
    case 2:
      monthL = 28;
      break;

    case 4:
      monthL = 30;
      break;


    case 6:
        monthL = 30;
        break;

    case 9:
      monthL = 30;
      break;

    case 11:
      monthL = 30;
      break;

    default:
      monthL = 31;
    }

  printf("| L | M | M | J | V | S | D |");
  printf("\n");

  for(int x = 0; x < monthL; x++){
        is = false;
        for(int y = 0; y<7; y++){

            if(weekdays[y] == dayofweek(x, m, ye)){


                f = true;
                for(int z = 0; z < 31; z++){


                    if(days[z] == x){

                        is = true;

                      }


                  }
                if(x < 10 && is){
                    printf(" 0%d ", x);
                  }
                else if(is){
                    printf(" %d ", x);
                  }

                if(!is){

                    printf(" ** ");

                  }
              }
            if(!f){

                printf(" -- ");
                weekCounter++;

              }

          }

        weekCounter++;
        if(weekCounter == 7){

            printf("\n");
            weekCounter = 0;

          }


    }


  }

void ProgrameCalendarRoute(){
    system("cls");
    printf("\n");
    printf("ProgrameCalendarRoute");
  }

void RouteRouteCalendarData(){
    system("cls");
    printf("\n");
    printf("RouteRouteCalendarData");
  }

void MonthCalendarTreep(){
    CityConnections rute;
    int option1 = 0;
    int option2 = 0;
    int month = 0;
    int year = 0;
    IntegerArrayMonth days;
    system("cls");
    printf("\n");
    printf("Lista de ciudades actualmente en el sistema.");
      printf("\n");
      for(int i = 0; i<200; i++){
        if(strlen(allCities[i].cityName) > 1){
              printf("\n");
              printf("%d   ", i);
              printf(allCities[i].cityName);
          }
      }
    printf("\n");
    printf("Teclear el numero de la ciudad destino.");
    printf("\n");
    scanf("%d", &option2);
    for(int x = 0; x<200; x++){

        if(strcmp(ManualJourneys [x].end.cityName, allCities[option2].cityName) == 0){

            rute = ManualJourneys [x];

          }

      }
    printf("Teclear el mes.");
    printf("\n");
    scanf("%d", &month);

    printf("Teclear el año.");
    printf("\n");
    scanf("%d", &year);

    for(int x = 0; x<200; x++){

        if(rute.calendar[x].day > 0 && rute.calendar[x].mont == month){

            days[rute.calendar[x].day] = rute.calendar[x].day;

          }

      }
    system("cls");
    drawCalendar(month,year,days);
    printf("\n");
    printf("Teclear cualquier numero para continuar.");
    printf("\n");
    scanf("%d", &option2);


  }

void TreepInformation(){
    CityConnections rute;
    int option1 = 0;
    int option2 = 0;
    int month = 0;
    int year = 0;
    IntegerArrayMonth days;
    system("cls");
    printf("\n");
    printf("Lista de ciudades actualmente en el sistema.");
      printf("\n");
      for(int i = 0; i<200; i++){
        if(strlen(allCities[i].cityName) > 1){
              printf("\n");
              printf("%d   ", i);
              printf(allCities[i].cityName);
          }
      }
    printf("\n");
    printf("Teclear el numero de la ciudad destino.");
    printf("\n");
    scanf("%d", &option2);
    for(int x = 0; x<200; x++){

        if(strcmp(ManualJourneys [x].end.cityName, allCities[option2].cityName) == 0){

            rute = ManualJourneys [x];

          }

      }
    printf("Teclear el mes.");
    printf("\n");
    scanf("%d", &month);

    printf("Teclear el año.");
    printf("\n");
    scanf("%d", &year);

    for(int x = 0; x<200; x++){

        if(rute.calendar[x].day > 0 && rute.calendar[x].mont == month){

            days[rute.calendar[x].day] = rute.calendar[x].day;

          }

      }
    system("cls");
    MakeRutemanualyFinal(rute);
    printf("\n");
    printf("Teclear cualquier numero para continuar.");
    printf("\n");
    scanf("%d", &option2);
  }


void createConnection(City newCity){

      int option;
      CityConnections newCityConnections;
      bool exist = false;
      int cityConnectionPos = 0;
      int cityConnectionLastConnection = 0;
      int newConnectioninexistingConnection = 0;
      int oldConnectioninexistingConnection = 0;
      for(int i = 0; i<200; i++){
        if(strlen(ConnectionsList[i].cityconnection.cityName) > 1){
              if(strcmp(ConnectionsList[i].cityconnection.cityName, newCity.cityName) == 0){
                    cityConnectionPos = i;
                    exist = true;
                }
            }
      }

      if(!exist){
          newCityConnections.cityconnection = newCity;
          lastConection++;
          ConnectionsList[lastConection] = newCityConnections;
          createConnection(newCity);
        }

      printf("Lista de ciudades actualmente en el sistema.");
      printf("\n");
      for(int i = 0; i<200; i++){
        if(strlen(allCities[i].cityName) > 1){
              printf("\n");
              printf("%d   ", i);
              printf(allCities[i].cityName);
          }
      }
      printf("\n");
      printf("Teclear el numero de la ciudad a la que quiere Connectar.");
      printf("\n");
      scanf("%d", &option);

      for(int i = 0; i<200; i++){
        if(strlen(ConnectionsList[i].cityconnection.cityName) > 1){

                    cityConnectionLastConnection = i;

                }
            }

      cityConnectionLastConnection++;
      ConnectionsList[cityConnectionPos].ConnectionList[cityConnectionLastConnection].cityconnection = allCities[option];


      for(int i = 0; i<200; i++){
        if(strlen(ConnectionsList[i].cityconnection.cityName) > 1){

                if(strcmp(ConnectionsList[i].cityconnection.cityName, allCities[option].cityName) == 0){
                      oldConnectioninexistingConnection = i;
                      for(int y = 0; y<200; y++){
                        if(strlen(ConnectionsList[i].ConnectionList[y].cityconnection.cityName) > 1){

                                    newConnectioninexistingConnection = y;

                                }
                      }
                    }

                }

        }
       newConnectioninexistingConnection ++;
       ConnectionsList[oldConnectioninexistingConnection].ConnectionList[newConnectioninexistingConnection].cityconnection = newCity;
       printf("\n");
       printf("Teclear Cualquier numero para continuar.");
       printf("\n");
       scanf("%d", &option);

      }


void AddConnections(City newCity){

    CityConnections newCityConnections;
    int option;

    system("cls");
    printf("\n");
    printf("Crear una nueva Connexion.");
    printf("\n");
    printf("    Crear Conexion: (Pulse 1)");
    printf("\n");
    printf("    Volver:         (Pulse 3)");
    printf("\n");
    printf("\n");
    printf("Teclear una opcion valida (1|2|3)?");
    printf("\n");
    scanf("%d", &option);
    switch(option){

        case 1:
          system("cls");
          createConnection(newCity);
          AddConnections(newCity);
          break;

        case 3:
          break;

      }
    printf("\n");

  }

void AddCity(){

    int option;
    City newCity;
    StringArray cityname;
    system("cls");
    printf("\n");
    printf("Crear una nueva ciudad.");
    printf("\n");

    printf("\n");
    printf("Teclear el Nombre d ela ciudad.");
    printf("\n");
    scanf("%s", &newCity.cityName);
    printf("\n");
    printf("Teclear el Codigo Postal de la ciudad.");
    printf("\n");
    scanf("%d", &newCity.postalCode);
    lastCity ++;
    allCities[lastCity] = newCity;
    AddConnections(allCities[lastCity]);
  }


CityConnections MakeRuteCalendar(CityConnections manualRute){

    int day;
    int mont;
    int year;
    int hour;
    int option;
    int lastCalendar = 0;
    system("cls");
    printf("\n");
    printf("Inserte el dia:");
    printf("\n");
    scanf("%d", &day);
    printf("\n");
    printf("Inserte el mes:");
    printf("\n");
    scanf("%d", &mont);
    printf("\n");
    printf("Inserte el año:");
    printf("\n");
    scanf("%d", &year);
    printf("\n");
    printf("Inserte la hora:");
    printf("\n");
    scanf("%d", &hour);

    for(int x = 0; x<20; x++){

        if(manualRute.calendar[x].day > 0){

              lastCalendar = x;

          }

      }
    lastCalendar++;
    manualRute.calendar[lastCalendar].day = day;
    manualRute.calendar[lastCalendar].mont = mont;
    manualRute.calendar[lastCalendar].year = year;
    manualRute.calendar[lastCalendar].hour = hour;

    printf("\n");
    printf("Crear una nueva Fecha.");
    printf("\n");
    printf("    Crear Fecha: (Pulse 1)");
    printf("\n");
    printf("    Volver:      (Pulse 3)");
    printf("\n");
    printf("\n");
    printf("Teclear una opcion valida (1|3)?");
    printf("\n");
    scanf("%d", &option);
    switch(option){

        case 1:
          system("cls");
          manualRute = MakeRuteCalendar(manualRute);
          break;

        case 3:
          break;

      }
    printf("\n");
    return manualRute;

  }

void CalendarRute(){
    int option;
    system("cls");
    printf("\n");
    printf("Rutas Manuales Activas.");
    for(int i = 0; i<200; i++){
      if(strlen(ManualJourneys [i].start.cityName) > 1){
            printf("\n");
            printf("%d   ", i);
            printf("Desde: ");
            printf(ManualJourneys [i].start.cityName);
            printf("    ");
            printf("Hasta: ");
            printf(ManualJourneys [i].end.cityName);

        }
    }
    printf("\n");
    printf("Teclear el numero de la ruta que desea Modificar?");
    printf("\n");
    printf("\n");
    scanf("%d", &option);
    system("cls");
    ManualJourneys [option] = MakeRuteCalendar(ManualJourneys [option]);
    printf("Teclear cualquier numero para continuar");
    printf("\n");
    scanf("%d", &option);
  }

void DefineRuteCalendar(){

    int option;
    system("cls");
    printf("Importante: Solo se pued emodificar el calendario de las rutas creadas manualmente.");
    printf("\n");
    printf("    Elegir Rutas Manuales:        (Pulse 1)");
    printf("\n");
    printf("    Volver:                       (Pulse 3)");
    printf("\n");
    printf("\n");
    scanf("%d", &option);
    switch(option){

        case 1:
          system("cls");
          CalendarRute();
          break;

        case 3:
          break;

      }

  }

void VisualiceRouteAutomaticalyAll(){
    int option;
    printf("\n");
    for(int i = 0; i<200; i++){
      if(strlen(AllJourneys[i].start.cityName) > 1){
            printf("\n");
            MakeRute(AllJourneys[i].start, AllJourneys [i].end);
            printf("\n");
        }
    }
    printf("\n");

  }

void VisualiceRouteManualAll(){
    int option;
    printf("\n");
    for(int i = 0; i<200; i++){
      if(strlen(ManualJourneys [i].start.cityName) > 1){
             printf("\n");
             MakeRutemanualy(ManualJourneys [i]);
             printf("\n");

        }
    }
  }

void showAllRutes(){
    int option;
    printf("\n");
    printf("Rutas Automaticas del sistema.");
    printf("\n");
    VisualiceRouteAutomaticalyAll();
    printf("\n");
    printf("Rutas Manuales del sistema.");
    printf("\n");
    VisualiceRouteManualAll();
    printf("\n");
    printf("Teclear cualquier numero para continuar");
    printf("\n");
    scanf("%d", &option);

  }

void ShowRuteDay(){
    CityConnections rute;
    int option1 = 0;
    int option2 = 0;
    int month = 0;
    int day = 0;
    IntegerArrayMonth days;
    system("cls");
    printf("\n");
    printf("Teclear el mes.");
    printf("\n");
    scanf("%d", &month);

    printf("Teclear el dia.");
    printf("\n");
    scanf("%d", &day);
    for(int x = 0; x<200; x++){
        for(int y = 0; y<20; y++){
          if(ManualJourneys[x].calendar[y].mont == month && ManualJourneys[x].calendar[y].day == day){
              printf("\n");
              MakeRutemanualy(ManualJourneys [x]);
              printf("\n");

            }
        }

      }
    printf("\n");
    printf("Rutas Automaticas: Importante!! Las rutas automaticas se efectuan diariamente.");
    printf("\n");
    printf("\n");
    printf("Teclear cualquier numero para continuar.");
    printf("\n");
    scanf("%d", &option2);
  }

void RemoveRouteAutomaticaly(){
    int option;
    system("cls");
    printf("\n");
    printf("Rutas Automaticas Activas.");
    for(int i = 0; i<200; i++){
      if(strlen(AllJourneys [i].start.cityName) > 1){
            printf("\n");
            printf("%d   ", i);
            printf("Desde: ");
            printf(AllJourneys [i].start.cityName);
            printf("    ");
            printf("Hasta: ");
            printf(AllJourneys [i].end.cityName);

        }
    }
    printf("\n");
    printf("Teclear el numero de la ruta que desea eliminar?");
    printf("\n");
    printf("\n");
    scanf("%d", &option);
    AllJourneys[option].end = Default;
    AllJourneys[option].start = Default;
    printf("Teclear cualquier numero para continuar");
    printf("\n");
    scanf("%d", &option);
  }

void RemoveRouteManual(){
    int option;
    system("cls");
    printf("Rutas Manuales Activas.");
    printf("\n");
    for(int i = 0; i<200; i++){
      if(strlen(ManualJourneys [i].start.cityName) > 1){
            printf("\n");
            printf("%d   ", i);
            printf("Desde: ");
            printf(ManualJourneys [i].start.cityName);
            printf("    ");
            printf("Hasta: ");
            printf(ManualJourneys [i].end.cityName);

        }
    }
    printf("\n");
    printf("Teclear el numero de la ruta que desea eliminar?");
    printf("\n");
    printf("\n");
    scanf("%d", &option);
    system("cls");
    ManualJourneys[option].cityconnection = Default;
    ManualJourneys[option].start = Default;
    ManualJourneys[option].end = Default;
    for(int x = 0; x<20; x++){
          ManualJourneys[option].calendar[x] = DefaultCalendar;
      }

    printf("Teclear cualquier numero para continuar");
    printf("\n");
    scanf("%d", &option);
  }


void RemoveRute(){

      int option;
      system("cls");
      printf("\n");
      printf("    Borrar ruta Manualmente:     (Pulse 1)");
      printf("\n");
      printf("    Borrar ruta Automaticamente: (Pulse 2)");
      printf("\n");
      printf("    Volver:                      (Pulse 3)");
      printf("\n");
      printf("\n");
      scanf("%d", &option);
      switch(option){

          case 1:
            system("cls");
            RemoveRouteManual();
            CreateRoute();
            break;

          case 2:
            system("cls");
            RemoveRouteAutomaticaly();
            CreateRoute();
            break;

          case 3:
            break;

        }

  }


void Home(){
    int option;
    time_t rawtime = time(NULL);
    system("cls");
    printf("\n");
    printf("Estatcion de autobus Oviedo.");
    printf(" El tiempo es: %02d:%02d:%02d:%02d:%02d:%02d\n", localtime(&rawtime)->tm_mday, localtime(&rawtime)->tm_mon, localtime(&rawtime)->tm_year - 100, localtime(&rawtime)->tm_hour,
           localtime(&rawtime)->tm_min, localtime(&rawtime)->tm_sec);
    printf("\n");
    printf("Gestion de Rutas");
    printf("\n");
    printf("    Editar ruta:                      (Pulse 1)");
    printf("\n");
    printf("    Programar calendario de ruta:     (Pulse 2)");
    printf("\n");
    printf("    Listar datos de ruta y calendario:(Pulse 3)");
    printf("\n");
    printf("    Calendario mensual de trayecto:   (Pulse 4)");
    printf("\n");
    printf("    Informacion de viaje:             (Pulse 5)");
    printf("\n");
    printf("    Anadir Ciudad:                    (Pulse 6)");
    printf("\n");
    printf("    Mostrar Rutas Estacion:           (Pulse 7)");
    printf("\n");
    printf("    Borrar Ruta:                      (Pulse 8)");
    printf("\n");
    printf("    Mostrar Rutas Dia:                (Pulse 9)");
    printf("\n");
    printf("    DarBillete:                       (Pulse 10)");
    printf("\n");
    printf("    Salir:                            (Pulse 11)");
    printf("\n");
    printf("Teclear una opcion valida (1|2|3|4|5|6|7)?");
    printf("\n");
    scanf("%d", &option);
    switch(option){

        case 1:
          EditRoute();
          Home();
          break;

        case 2:
          DefineRuteCalendar();
          Home();
          break;

        case 3:
          VisualiceRoute();
          Home();
          break;

        case 4:
          MonthCalendarTreep();
          Home();
          break;

        case 5:
          TreepInformation();
          Home();
          break;

        case 6:
          AddCity();
          Home();
          break;

        case 7:
          showAllRutes();
          Home();
          break;

        case 8:
          RemoveRute();
          Home();
          break;

        case 9:
          ShowRuteDay();
          Home();
          break;

        case 10:
          VisualiceRoute();
          Home();
          break;


        case 11:
          break;

        default:
          Home();
      }
  }


int main()
{
  DefineDefaultConections();
  DefineDefaultJourneys ();
  defineAllCities();
  Home();
  return 0;
}
