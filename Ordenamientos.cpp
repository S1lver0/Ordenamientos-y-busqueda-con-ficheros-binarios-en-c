#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

struct alumno
{
    char codigo[50];
    char nombre[50];
    int edad;

}alu2[50];

//prototipos de funcion
//BUSQUEDA Y INTERCAMBIO
void busquedasecuencial(alumno[],int,int);
void inserciondirecta(alumno[],int,int);
void insercionbinaria(alumno[],int,int);
void shell(alumno[],int,int);
void busquedabinaria(alumno[],int,int);
void quicksort(alumno[],int,int,int);
void selecciondirecta(alumno[],int,int);
void ordenamiento_por_heapsort(alumno *,int,int);
void heapify(alumno *,int,int,int);
//hash
int Dindex(int,int);
void inicio(int[],int[],int);
void HASHING(int,int);
int as(char[]);

//MENU
int menu();
int criterio();
///PARA MOSTRAR
void mostrardatos();
void mostrar_al(alumno);
void mostrar_archivo(char *);

//PARA GUARDAR VALIDAR Y INGRESAR
void guardar_archivo(char *,alumno &);
int recarga(char *,alumno[]);
int ingresar_al(alumno &,int,alumno[]);
void regre(alumno[],alumno[],int);

///PRINCIPAL
int main(){
    alumno alu[50];
    alumno x;
    int opc,total=0,vali=0,cri,con1,con5;
    string con;
    char nombre_ar[60],op,re='n';
    do{
        opc=menu();
        switch (opc){
            //PARA LEER ARCHIVO O CREAR UNO 
        case 1:
            vali=1;
            system("cls");
            cout<<"\nRUTA Y NOMBRE ARCHIVO : ";cin>>nombre_ar;
            total=recarga(nombre_ar,alu);
            if(total!=0){
                cout<<"\nEl archivo ingresado cuenta con datos desea agregar mas datos? ingrese s/n :";
                cin>>re;
            }
            else{
                cout<<"\nEl archivo que ingreso no existe se procedera a crear uno y debera agregarle datos";
                cout<<"\n\n\tPresione una tecla para continuar :";cin>>con;
                re='s';
            }
            if(re=='s'||re=='S'){
                do{
                    system("cls");
                    total=ingresar_al(x,total,alu);
                    guardar_archivo(nombre_ar,x);
                    cout<<"\n\n\tIngresara mas datos (s/n): ?";
                    cin>>op;
                }while(op=='s'||op=='S');
            }
            break;

            //PARA MOSTRAR DATOS DEL ARCHIVO
        case 2:
            system("cls");
            if(vali!=0){
                mostrardatos();
                mostrar_archivo(nombre_ar);
                cout<<"\n\n\tPresione una tecla para continuar :";cin>>con;
            }
            else{
                cout<<"\n\nTIENE QUE INGRESAR LEER DATOS ANTES DE ENTRAR A ESTA OPCION";
                cout<<"\n\n\tIngrese una tecla para continuar :"; cin>>con;
            }
            break;
        case 3:
            //PARA AGREGAR MAS DATOS
            system("cls");
            if(vali!=0){
                total=ingresar_al(x,total,alu);
                guardar_archivo(nombre_ar,x);
            }
            else{
                cout<<"\n\nTIENE QUE INGRESAR LEER DATOS ANTES DE ENTRAR A ESTA OPCION";
                cout<<"\n\n\tIngrese una tecla para continuar :"; cin>>con;
            }
            break;
            ///PARA ORDENADAR DATOS
        case 4:
            if(vali!=0){
                system("cls");
                cout<<"\n-----------------MENU ORDENAR------------------";
                cout<<"\n\t\t1.-SELECCION DIRECTA";        
                cout<<"\n\t\t2.-INSERCION DIRECTA";
                cout<<"\n\t\t3.-INSERCION BINARIA";
                cout<<"\n\t\t4.-SHELL";
                cout<<"\n\t\t5.-QUICK-SORT";
                cout<<"\n\t\t6.-HEAP-SORT";
                cout<<"\n\t\t7.-SALIR";
                cout<<"\n-----------------------------------------------";
                cout<<"\n\tIngrese la opcion : ";cin>>con1;
                while(con1<0||con1>7){
                    cout<<"\nIngrese un dato valido entre 1,2,3,4,5..7";cin>>con1;
                }
                //selecion directo

                if(con1==1){
                    system("cls");
                    cri=criterio();
                    selecciondirecta(alu,total,cri);
                    mostrardatos();
                    for(int i=0;i<=total-1;i++){
                        cout<<"\n";
                        mostrar_al(alu[i]);
                    }
                    regre(alu,alu2,total);
                }


                //insercion directa

                if(con1==2){
                    system("cls");
                    cri=criterio();
                    inserciondirecta(alu,total,cri);
                    mostrardatos();
                    for(int i=0;i<=total-1;i++){
                        cout<<"\n";
                        mostrar_al(alu[i]);
                    }
                    regre(alu,alu2,total);
                }

                //insercion binaria

                if(con1==3){
                    system("cls");
                    cri=criterio();
                    insercionbinaria(alu,total,cri);
                    mostrardatos();
                    for(int i=0;i<=total-1;i++){
                        cout<<"\n";
                        mostrar_al(alu[i]);
                    }
                    regre(alu,alu2,total);
                }

                //shell

                if(con1==4){
                    system("cls");
                    cri=criterio();
                    shell(alu,total,cri);
                    mostrardatos();
                    for(int i=0;i<=total-1;i++){
                        cout<<"\n";
                        mostrar_al(alu[i]);
                    }
                    regre(alu,alu2,total);
                }

                if(con1==5){
                    system("cls");
                    cri=criterio();
                    quicksort(alu,0,total-1,cri);
                    mostrardatos();
                    for(int i=0;i<=total-1;i++){
                        cout<<"\n";
                        mostrar_al(alu[i]);
                    }
                    regre(alu,alu2,total);
                }

                if(con1==6){
                    system("cls");
                    cri=criterio();
                    ordenamiento_por_heapsort(alu,total,cri);
                    mostrardatos();
                    for(int i=0;i<=total-1;i++){
                        cout<<"\n";
                        mostrar_al(alu[i]);
                    }
                    regre(alu,alu2,total);
                }
            }
            else{
                cout<<"\n\nTIENE QUE INGRESAR LEER DATOS ANTES DE ENTRAR A ESTA OPCION";
            }
            cout<<"\n\n\tIngrese una tecla para continuar :"; cin>>con;
            break;
            
        case 5:
            system("cls");
            if(vali!=0){
                system("cls");
                cout<<"\n-----------------MENU ORDENAR------------------";
                cout<<"\n\t\t1.-BUSQUEDA SECUENCIAL";        
                cout<<"\n\t\t2.-BUSQUEDA BINARIA";
                cout<<"\n\t\t3.-BUSQUEDA HASHING";
                cout<<"\n\t\t4.-SALIR";
                cout<<"\n-----------------------------------------------";
                cout<<"\n\tIngrese la opcion : ";cin>>con5;
                while(con5<0||con5>4){
                    cout<<"\nIngrese un dato valido entre 1,2,3,4";cin>>con5;
                }
                switch (con5){
                case 1: 
                    cri=criterio();
                    busquedasecuencial(alu,total-1,cri);
                    break;
                case 2:
                    cri=criterio();
                    busquedabinaria(alu,total,cri);
                    break;
                case 3:
                    cri=criterio();
                    HASHING(total,cri);
                    break;
                }
            }
            else{
                cout<<"\n\nTIENE QUE INGRESAR LEER DATOS ANTES DE ENTRAR A ESTA OPCION";
                cout<<"\n\n\tIngrese una tecla para continuar :"; cin>>con;
            }
            break;
        }

    }while(opc!=6);

    return 0;
}

int menu(){
    system("color 9");
    system("cls");
    int op;
    cout<<"\n\t\t--------------MENU--------------";
    cout<<"\n\t\t1.-LEER DATOS";
    cout<<"\n\t\t2.-MOSTRAR DATOS";
    cout<<"\n\t\t3.-AGREGAR DATOS";
    cout<<"\n\t\t4.-ORDENAR DATOS";
    cout<<"\n\t\t5.-BUSCAR DATO";
    cout<<"\n\t\t6.-SALIR";
    cout<<"\n\t\t-------------------------------";
    cout<<"\n\t\t\tLEER OPCION :";cin>>op;
    while(op<1||op>6){
        cout<<"\nIngrese una opcion valida : ";cin>>op;
    }
    return op;
}


void mostrardatos(){
    cout<<"\t\t\t------------------------------------------------------------";
    cout<<"\n\t\t\t|                    MOSTRANDO-DATOS                       |";
    cout<<"\n\t\t\t------------------------------------------------------------";
}

void mostrar_al(alumno x){
    cout<<"\n\t\t\tCodigo :"<<x.codigo;
    cout<<"\n\t\t\tNombre: "<<x.nombre;
    cout<<"\n\t\t\tEDAD : "<<x.edad;
    cout<<"\n\t\t\t------------------------------------------------------------";
}

int criterio(){
    system("cls");
    int con2;
    cout<<"\n----------------CRITERIO-----------------";
    cout<<"\n\t\t1.-CODIGO ";
    cout<<"\n\t\t2.-NOMBRE ";
    cout<<"\n\t\t3.-EDAD ";
    cout<<"\n----------------------------------------------------";

    cout<<"\n\t\tIngrese la opcion : ";cin>>con2;
    while(con2<1||con2>3){
        cout<<"\nIngrese una opcion valida : ";cin>>con2;
    }
    return con2;
}

//FUNCIONES PARA FICHEROS


void mostrar_archivo(char *nomb){
    fstream entrada(nomb,ios::in|ios::binary);
    alumno y;
    int i=0;
    while(!entrada.eof()){ 
        entrada.read((char *)&y,sizeof(y));
        if(entrada.good()){
            cout<<"\n";
            mostrar_al(y);
        }
    }
}


void guardar_archivo(char *nomb,alumno &x){
    fstream salida(nomb,ios::out|ios::binary|ios::app);
    salida.write((char *)&x,sizeof(x));
    salida.close();
}


int ingresar_al(alumno &x,int Total,alumno Alu[]){
    cout<<"Codigo : ";cin>>x.codigo;
    cout<<"Nombre : ";cin>>x.nombre;
    cout<<"EDAD : ";cin>>x.edad;
    Alu[Total]=x;
    alu2[Total]=x;
    fflush(stdin);
    return (Total+1);
}
////////////////////////////////////////////////////


//FUNCION PARA RECARGAR DE DATOS Y COMBROBAR EL TOTAL

int recarga(char *nomb,alumno Alu[]){
    int i=0;
    fstream entrada(nomb,ios::in|ios::binary);
    if(!entrada.fail()){
        alumno y;
        while(!entrada.eof()){
            entrada.read((char *)&y,sizeof(y));
            if(entrada.good()){
                Alu[i]=y;
                alu2[i]=y;
                i=i+1;
            }
        }
        return i;
    }
    return 0;
}


///FUNCIONES DE BUSQUEDA Y INTERCAMBIO


void intercambiodire(alumno Alu[],int Total,int key){
    int i,j;
    alumno aux;

    if(key==1){
    ///INTERCAMBIO DIRECTO ATRIBUTO "CODIGO"
        for(i=1;i<=Total;i++){
            for(j=0;j<=Total-i;j++){
                if((strcmp(Alu[j].codigo,Alu[j+1].codigo))>0){
                    aux=Alu[j];
                    Alu[j]=Alu[j+1];
                    Alu[j+1]=aux;
                }
            }
        }
    }

    if(key==2){
        ///INTERCAMBIO DIRECTO ATRIBUTO "NOMBRE"

        for(i=1;i<=Total;i++){
            for(j=0;j<=Total-i;j++){
                if((strcmp(Alu[j].nombre,Alu[j+1].nombre))>0){
                    aux=Alu[j];
                    Alu[j]=Alu[j+1];
                    Alu[j+1]=aux;
                }
            }
        }

    }

    if(key==3){
        ///INTERCAMBIO DIRECTO ATRIBUTO "EDAD"
        
        for(i=1;i<=Total;i++){
            for(j=0;j<=Total-i;j++){
                if(Alu[j].edad>Alu[j+1].edad){
                    aux=Alu[j];
                    Alu[j]=Alu[j+1];
                    Alu[j+1]=aux;
                }
            }
        }

    }

}


void busquedasecuencial(alumno Alu[],int can,int key){
    float prom; string pa;
    char cod[100];
    int i=0,cen=0,posi;


    //busqueda por atributo "CODIGO"
    if(key==1){
        system("cls");
        mostrardatos();
        for(i=0;i<=can;i++){
            cout<<"\n";
            mostrar_al(Alu[i]);
        }
        i=0;
        cout<<"\n\nBUSQUEDA SECUENCIAL CRITERIO: <CODIGO>";
        cout<<"\nIngrese el codigo para realizar la busqueda  :";cin>>cod;
        while(cen==0&&i<=can){
            if((strcmp(Alu[i].codigo,cod))==0){
                cen=1;
                posi=i;
            }
            i=i+1;
        }

    }

    //busqueda por atributo "NOMBRE"
    if(key==2){
        system("cls");
        mostrardatos();
        for(i=0;i<=can;i++){
            cout<<"\n";
            mostrar_al(Alu[i]);
        }
        i=0;
        cout<<"\n\nBUSQUEDA SECUENCIAL CRITERIO: <NOMBRE>";
        cout<<"\n\nIngrese el nombre para realizar la busqueda  :";cin>>cod;
        while(cen==0&&i<=can){
            if((strcmp(Alu[i].nombre,cod))==0){
                cen=1;
                posi=i;
            }
            i=i+1;
        }
        
    }
    //busqueda por atributo "EDAD"
    if(key==3){
        system("cls");
        mostrardatos();
        for(i=0;i<=can;i++){
            cout<<"\n";
            mostrar_al(Alu[i]);
        }
        i=0;
        cout<<"\n\nBUSQUEDA SECUENCIAL CRITERIO: <EDAD>";
        cout<<"\n\nIngrese el edad para realizar la busqueda  :";cin>>prom;
        while(cen==0&&i<=can){
            if(Alu[i].edad==prom){
                cen=1;
                posi=i;
            }
            i=i+1;
        }
        
    }

    if(cen==0){
        cout<<"\n\nEl dato que ingreso no se encuentra en la base de datos";
    }
    else{
        cout<<"\n<El dato se encuentra en la ubicacion numero ["<<posi+1<<"]  del arreglo>";
        cout<<"\n\nMostrando el registro completo de esa posicion";
        cout<<"\n\t\t\t--------------------------------------------------";
        mostrar_al(Alu[posi]);
    }
    cout<<"\n\n\tIngrese una tecla para regresar :";cin>>pa;
}


void inserciondirecta(alumno ALU[],int can,int key){
    int i,h;
    alumno aux;

    //insercion directa por atributo "CODIGO"

    if(key==1){
        for(i=2;i<=can;i++){
            aux=ALU[i-1];
            h=i-1;
            while(h>0&&(strcmp(aux.codigo,ALU[h-1].codigo))<0){
                ALU[h]=ALU[h-1];
                h=h-1;
            }
            ALU[h]=aux;
        }
    }

    //insercion directa por atributo "NOMBRE"

    if(key==2){
        for(i=2;i<=can;i++){
            aux=ALU[i-1];
            h=i-1;
            while(h>0&&(strcmp(aux.nombre,ALU[h-1].nombre))<0){
                ALU[h]=ALU[h-1];
                h=h-1;
            }
            ALU[h]=aux;
        }
    }


    //insercion directa por atributo "EDAD"

    if(key==3){
        for(i=2;i<=can;i++){
            aux=ALU[i-1];
            h=i-1;
            while(h>0&&aux.edad<ALU[h-1].edad){
                ALU[h]=ALU[h-1];
                h=h-1;
            }
            ALU[h]=aux;
        }
    }

}

/////////////////////////////////////////////////////////////////////////

//5.-metodo insercion binaria

void insercionbinaria(alumno ALU[],int can,int key){
    int i,iz,der,m,j;
    alumno aux;

    //insercion binaria atributo "CODIGO"

    if(key==1){
        for(i=1;i<can;i++){
            aux=ALU[i];
            iz=0;
            der=i-1;
            while(iz<=der){
                m=(iz+der)/2;
                if((strcmp(aux.codigo,ALU[m].codigo))<=0){
                    der=m-1;
                }
                else{
                    iz=m+1;
                }
            }

            j=i-1;

            while(j>=iz){
                ALU[j+1]=ALU[j];
                j=j-1;
            }
            ALU[iz]=aux;
        }
    }

    //insercion binaria atributo "NOMBRE"

    if(key==2){
        for(i=1;i<can;i++){
            aux=ALU[i];
            iz=0;
            der=i-1;
            while(iz<=der){
                m=(iz+der)/2;
                if((strcmp(aux.nombre,ALU[m].nombre))<=0){
                    der=m-1;
                }
                else{
                    iz=m+1;
                }
            }

            j=i-1;

            while(j>=iz){
                ALU[j+1]=ALU[j];
                j=j-1;
            }

            ALU[iz]=aux;
        }


    }

    //insercion binaria atributo "EDAD"

    if(key==3){
        for(i=1;i<can;i++){
            aux=ALU[i];
            iz=0;
            der=i-1;
            while(iz<=der){
                m=(iz+der)/2;
                if(aux.edad<=ALU[m].edad){
                    der=m-1;
                }
                else{
                    iz=m+1;
                }
            }

            j=i-1;

            while(j>=iz){
                ALU[j+1]=ALU[j];
                j=j-1;
            }

            ALU[iz]=aux;
        }

    }

}

void shell(alumno ALU[],int can,int key){
    int m=can+1,cen,i;
    alumno aux;

    //METODO SHEL  ATRIBUTO "CODIGO"
    
    if(key==1){
        while(m>1){
            m=m/2;
            cen=1;
            while(cen==1){
                cen=0;
                i=0;

                while((i+m)<can){
                    if((strcmp(ALU[i].codigo,ALU[i+m].codigo)>0)){
                        aux=ALU[i];
                        ALU[i]=ALU[i+m];
                        ALU[i+m]=aux;
                        cen=1;
                    }
                    i=i+1;
                }
            }
        }
    }

    //METODO SHELL ATRIBUTO "NOMBRE"

    if(key==2){

        while(m>1){
            m=m/2;
            cen=1;
            while(cen==1){
                cen=0;
                i=0;

                while((i+m)<can){
                    if((strcmp(ALU[i].nombre,ALU[i+m].nombre)>0)){
                        aux=ALU[i];
                        ALU[i]=ALU[i+m];
                        ALU[i+m]=aux;
                        cen=1;
                    }
                    i=i+1;
                }
            }
        }
        
    }

    //METODO SHELL ATRIBUTO "EDAD"

    if(key==3){

        while(m>1){
            m=m/2;
            cen=1;
            while(cen==1){
                cen=0;
                i=0;

                while((i+m)<can){
                    if(ALU[i].edad>ALU[i+m].edad){
                        aux=ALU[i];
                        ALU[i]=ALU[i+m];
                        ALU[i+m]=aux;
                        cen=1;
                    }
                    i=i+1;
                }
            }
        }
        
    }

}


void regre(alumno ALU[], alumno ALU2[],int can){
    int i;

    for(i=0;i<can;i++){
        ALU[i]=ALU2[i];
    }
}



void busquedabinaria(alumno ALU[],int can,int key){
    float prom; string pa; int ini; int m;int fin,i;
    char cod[100];
    int cen=0,posi;
    shell(ALU,can,key);
    ini=0;
    fin=can-1;
    m=(ini+fin)/2;

    //busqueda binaria atributo "codigo"
    if(key==1){
        system("cls");
        mostrardatos();
        for(i=0;i<can;i++){
            cout<<"\n";
            mostrar_al(ALU[i]);
        }
        cout<<"\n\nBUSQUEDA BINARIA CRITERIO: <CODIGO>";
        cout<<"\n\nIngrese el nombre para realizar la busqueda  :";cin>>cod;

        while(ini<=fin&&cen==0){
            if((strcmp(cod,ALU[m].codigo))>=0){
                if(strcmp(ALU[m].codigo,cod)==0){
                    cen=1;
                    posi=m;
                }
                ini=m+1;                
            }
            else{
                fin=m-1;
            }

            m=(ini+fin)/2;
        }

    }

    //busqueda binaria atributo "nombre"   

    if(key==2){
        system("cls");
        mostrardatos();
        for(i=0;i<can;i++){
            cout<<"\n";
            mostrar_al(ALU[i]);
        }
        cout<<"\n\nBUSQUEDA BINARIA CRITERIO: <NOMBRE>";
        cout<<"\n\nIngrese el nombre para realizar la busqueda  :";cin>>cod;

        while(ini<=fin&&cen==0){
            if((strcmp(cod,ALU[m].nombre))>=0){
                if(strcmp(ALU[m].nombre,cod)==0){
                    cen=1;
                    posi=m;
                }
                ini=m+1;                
            }
            else{
                fin=m-1;
            }

            m=(ini+fin)/2;
        }

    }

    //busqueda binaria atributo "EDAD"

    if(key==3){
        system("cls");
        mostrardatos();
        for(i=0;i<can;i++){
            cout<<"\n";
            mostrar_al(ALU[i]);
        }
        cout<<"\n\nBUSQUEDA BINARIA CRITERIO: <EDAD>";
        cout<<"\n\nIngrese el nombre para realizar la busqueda  :";cin>>prom;

        while(ini<=fin&&cen==0){
            if(prom>=ALU[m].edad){
                if(ALU[m].edad==prom){
                    cen=1;
                    posi=m;
                }
                ini=m+1;                
            }
            else{
                fin=m-1;
            }

            m=(ini+fin)/2;
        }

    }


    if(cen==0){
        cout<<"\n\nEl dato que ingreso no se encuentra en la base de datos";
    }
    else{
        cout<<"\n<El dato se encuentra en la ubicacion numero ["<<posi+1<<"]  del arreglo>";
        cout<<"\n\nMostrando el registro completo de esa posicion";
        cout<<"\n\t\t\t--------------------------------------------------";
        mostrar_al(ALU[posi]);
    }

    cout<<"\n\n\tIngrese una tecla para regresar :";cin>>pa;
}

void quicksort(alumno ALU[],int ini,int fin,int key){
    int izq,der,cen,p;
    alumno aux;

    izq=ini;
    der=fin;
    p=ini;
    cen=1;

    //QUICKSORT ATRIBUTO "CODIGO"

    if(key==1){

        while(cen==1){
            cen=0;
            while((strcmp(ALU[p].codigo,ALU[der].codigo))<=0&&p!=der){
                der=der-1;
            }
            if(p!=der){
                aux=ALU[p];
                ALU[p]=ALU[der];
                ALU[der]=aux;
                p=der;

                while((strcmp(ALU[p].codigo,ALU[izq].codigo))>0&&p!=izq){
                    izq=izq+1;
                }

                if(p!=izq){
                    aux=ALU[p];
                    ALU[p]=ALU[izq];
                    ALU[izq]=aux;
                    p=izq;
                    cen=1;
                }

            
            }

        }
    }

    //QUICKSORT ATRIBUTO "NOMBRE"

    if(key==2){

        while(cen==1){
            cen=0;
            while((strcmp(ALU[p].nombre,ALU[der].nombre))<=0&&p!=der){
                der=der-1;
            }
            if(p!=der){
                aux=ALU[p];
                ALU[p]=ALU[der];
                ALU[der]=aux;
                p=der;

                while((strcmp(ALU[p].nombre,ALU[izq].nombre))>0&&p!=izq){
                    izq=izq+1;
                }

                if(p!=izq){
                    aux=ALU[p];
                    ALU[p]=ALU[izq];
                    ALU[izq]=aux;
                    p=izq;
                    cen=1;
                }

            
            }

        }


    }

    //QUICKSORT ATRIBUTO "EDAD"

    if(key==3){

        while(cen==1){
            cen=0;
            while(ALU[p].edad<=ALU[der].edad&&p!=der){
                der=der-1;
            }
            if(p!=der){
                aux=ALU[p];
                ALU[p]=ALU[der];
                ALU[der]=aux;
                p=der;

                while(ALU[p].edad>ALU[izq].edad&&p!=izq){
                    izq=izq+1;
                }

                if(p!=izq){
                    aux=ALU[p];
                    ALU[p]=ALU[izq];
                    ALU[izq]=aux;
                    p=izq;
                    cen=1;
                }

            
            }

        }


    }

    if((p-1)>ini){
        quicksort(ALU,ini,p-1,key);
    }

    if(fin>(p+1)){
        quicksort(ALU,p+1,fin,key);
    }


}

void HASHING(int Total,int key){
    system("cls");
    int i,dt,cen=10,recon=0,dat;
    char dato[50];
    string pa;
    int num[Total];
    int num2[Total];
    alumno hashi[Total];
    //funcion para inicializar ambos arreglos con -1
    inicio(num,num2,Total);

    mostrardatos();
    for(i=0;i<Total;i++){
        cout<<"\n";
        mostrar_al(alu2[i]);
    }


    //ingresando datos

    ///BUSQUEDA HASH POR CODIGO
    if(key==1){
    for(i=0;i<Total;i++){
        dt=as(alu2[i].codigo);
        //funcion Dindex para obtener el indice de la clave "dato"%"cantidad de datos"
        if(num[Dindex(dt,Total)]==-1){
            //con el indice obtenido se iguala el dato a la posicion del vector
            num[Dindex(dt,Total)]=1;
            hashi[Dindex(dt,Total)]=alu2[i];
        }
        else{
            //en el caso de no ser -1 significa que es una colision en la cual el segundo arreglo num2 que guarda numeros -1 cambiara un dato de la posicion que retorne la funcion Dindex a 1 indicando una colision
            num2[Dindex(dt,Total)]=1;
            recon=0,cen=10;
            //en el caso de haber colision tendremos que recorrer el arreglo desde el inicio y insertar el dato en un lugar que no tenga datos osea -1
            while(recon<Total&&cen==10){
                if(num[recon]==-1){
                    num[recon]=1;
                    hashi[recon]=alu2[i];
                    cen=5;
                }
                else{
                    recon=recon+1;
                }
            }
        }
    }

    ///para busqueda
    cout<<"\n\nIngrese el codigo a buscar :";cin>>dato;
    dat=as(dato);


    //compara el dato con el valor de la posicion Dindex de num
    if(strcmp(hashi[Dindex(dat,Total)].codigo,dato)==0){
        cout<<"\nEL DATO SE ENCUENTRA---MOSTRANDO LA ESTRUCTURA\n";
        mostrardatos();
        mostrar_al(hashi[Dindex(dat,Total)]);

    }
    //en el caso de que no sean iguales se pregunta si el valor tuvo colision 
    else{
        //se pone compara con 1 para comprobar si el dato colisiono o no recordando que num2 es nuestra tabla de colision
        //en el caso de que sea -1 indica que no hubo colision 
        //en el caso de cumplir el else tendra que hacer una busqueda secuencial desde la posi 0
        if(num2[Dindex(dat,Total)]==1){
            i=0,cen=10;
            while(i<Total&&cen==10){
                if(strcmp(hashi[i].codigo,dato)==0){
                    cen=5;
                }
                i=i+1;
            }

            if(cen==5){
                cout<<"\nEL DATO SE ENCUENTRA___MOSTRANDO LA ESTRUCTURA\n";
                mostrardatos();
                mostrar_al(hashi[i-1]);
            }
            else{
                cout<<"EL DATO NO SE ENCUENTRA EN EL ARREGLO DE ESTRUCTURAS";
            }
        }
        
        else{
            cout<<"EL DATO NO SE ENCUENTRA EN EL ARREGLO ESTRUCTURA";
        }
    }



    }

    
    //BUSQUEDA HASH POR NOMBRE

    if(key==2){
    for(i=0;i<Total;i++){
        dt=as(alu2[i].nombre);
        //funcion Dindex para obtener el indice de la clave "dato"%"cantidad de datos"
        if(num[Dindex(dt,Total)]==-1){
            //con el indice obtenido se iguala el dato a la posicion del vector
            num[Dindex(dt,Total)]=1;
            hashi[Dindex(dt,Total)]=alu2[i];
        }
        else{
            //en el caso de no ser -1 significa que es una colision en la cual el segundo arreglo num2 que guarda numeros -1 cambiara un dato de la posicion que retorne la funcion Dindex a 1 indicando una colision
            num2[Dindex(dt,Total)]=1;
            recon=0,cen=10;
            //en el caso de haber colision tendremos que recorrer el arreglo desde el inicio y insertar el dato en un lugar que no tenga datos osea -1
            while(recon<Total&&cen==10){
                if(num[recon]==-1){
                    num[recon]=1;
                    hashi[recon]=alu2[i];
                    cen=5;
                }
                else{
                    recon=recon+1;
                }
            }
        }
    }

    ///para busqueda
    cout<<"\n\nIngrese el numero a buscar :";cin>>dato;
    dat=as(dato);

    
    //compara el dato con el valor de la posicion Dindex de num
    if(strcmp(hashi[Dindex(dat,Total)].nombre,dato)==0){
        cout<<"\nEL DATO SE ENCUENTRA---MOSTRANDO LA ESTRUCTURA\n";
        mostrardatos();
        mostrar_al(hashi[Dindex(dat,Total)]);

    }
    //en el caso de que no sean iguales se pregunta si el valor tuvo colision 
    else{
        //se pone compara con 1 para comprobar si el dato colisiono o no recordando que num2 es nuestra tabla de colision
        //en el caso de que sea -1 indica que no hubo colision 
        //en el caso de cumplir el else tendra que hacer una busqueda secuencial desde la posi 0
        if(num2[Dindex(dat,Total)]==1){
            i=0,cen=10;
            while(i<Total&&cen==10){
                if(strcmp(hashi[i].nombre,dato)==0){
                    cen=5;
                }
                i=i+1;
            }

            if(cen==5){
                cout<<"\nEL DATO SE ENCUENTRA---MOSTRANDO LA ESTRUCTURA\n";
                mostrardatos();
                mostrar_al(hashi[i-1]);
            }
            else{
                cout<<"EL DATO NO SE ENCUENTRA EN EL ARREGLO DE ESTRUCTURAS";
            }
        }
        
        else{
            cout<<"EL DATO NO SE ENCUENTRA EN EL ARREGLO ESTRUCTURA";
        }
    }


    }


    ///BUSQUEDA HASH POR EDAD


    if(key==3){
    for(i=0;i<Total;i++){
        dt=alu2[i].edad;
        //funcion Dindex para obtener el indice de la clave "dato"%"cantidad de datos"
        if(num[Dindex(dt,Total)]==-1){
            //con el indice obtenido se iguala el dato a la posicion del vector
            num[Dindex(dt,Total)]=1;
            hashi[Dindex(dt,Total)]=alu2[i];
        }
        else{
            //en el caso de no ser -1 significa que es una colision en la cual el segundo arreglo num2 que guarda numeros -1 cambiara un dato de la posicion que retorne la funcion Dindex a 1 indicando una colision
            num2[Dindex(dt,Total)]=1;
            recon=0,cen=10;
            //en el caso de haber colision tendremos que recorrer el arreglo desde el inicio y insertar el dato en un lugar que no tenga datos osea -1
            while(recon<Total&&cen==10){
                if(num[recon]==-1){
                    num[recon]=1;
                    hashi[recon]=alu2[i];
                    cen=5;
                }
                else{
                    recon=recon+1;
                }
            }
        }
    }

    ///para busqueda
    cout<<"\n\nIngrese la edad a buscar :";cin>>dat;


    //compara el dato con el valor de la posicion Dindex de num
    if(dat==hashi[Dindex(dat,Total)].edad){
        cout<<"\nEL DATO SE ENCUENTRA---MOSTRANDO LA ESTRUCTURA\n";
        mostrardatos();
        mostrar_al(hashi[Dindex(dat,Total)]);

    }
    //en el caso de que no sean iguales se pregunta si el valor tuvo colision 
    else{
        //se pone compara con 1 para comprobar si el dato colisiono o no recordando que num2 es nuestra tabla de colision
        //en el caso de que sea -1 indica que no hubo colision 
        //en el caso de cumplir el else tendra que hacer una busqueda secuencial desde la posi 0
        if(num2[Dindex(dat,Total)]==1){
            i=0,cen=10;
            while(i<Total&&cen==10){
                if(hashi[i].edad==dat){
                    cen=5;
                }
                i=i+1;
            }

            if(cen==5){
                cout<<"\nEL DATO SE ENCUENTRA__MOSTRANDO LA ESTRUCTURA\n";
                mostrardatos();
                mostrar_al(hashi[i-1]);
            }
            else{
                cout<<"EL DATO NO SE ENCUENTRA EN EL ARREGLO DE ESTRUCTURAS";
            }
        }
        
        else{
            cout<<"EL DATO NO SE ENCUENTRA EN EL ARREGLO ESTRUCTURA";
        }
    }

    }
    cout<<"\n\n\tIngrese una tecla para regresar :";cin>>pa;

}

int Dindex(int dato,int can){
    int index;
    index=dato%can;
    return index;
}

//funcion que vuelve la tabla hashing y tabla de colision todo a -1
void inicio(int Num[],int Num2[],int can){
    int i;
    for(i=0;i<can;i++){
        Num[i]=-1;
        Num2[i]=-1;
    }
}

int as(char Dato[]){
    int datz=0,i;
    for(i=0;i<strlen(Dato);i++){
        datz=datz+Dato[i];
    }
    return datz;
}


void selecciondirecta(alumno ALU[],int can,int key){
    int i,h,j;
    alumno menor;


    //seleccion directa por atributo "CODIGO"

    if(key==1){
        for(i=0;i<can-1;i++){
            menor=ALU[i];
            h=i;
            for(j=i+1;j<can;j++){
                if((strcmp(ALU[j].codigo,menor.codigo))<0){
                    menor=ALU[j];
                    h=j;
                }

            }

            ALU[h]=ALU[i];
            ALU[i]=menor;

        }

    }


    //seleccion directa por atributo "NOMBRE"

    if(key==2){


        for(i=0;i<can-1;i++){
            menor=ALU[i];
            h=i;
            for(j=i+1;j<can;j++){
                if((strcmp(ALU[j].nombre,menor.nombre))<0){
                    menor=ALU[j];
                    h=j;
                }

            }

            ALU[h]=ALU[i];
            ALU[i]=menor;


        }

        
    }

    //seleccion directa por atributo "PROMEDIO"

    if(key==3){
        
        for(i=0;i<can-1;i++){
            menor=ALU[i];
            h=i;
            for(j=i+1;j<can;j++){
                if(ALU[j].edad<menor.edad){
                    menor=ALU[j];
                    h=j;
                }

            }

            ALU[h]=ALU[i];
            ALU[i]=menor;

        }
        
    }


}

void heapify(alumno *x, int n, int root,int key){
    if(key==1){
    int largest = root;
    int l = 2*root + 1;
    int r = 2*root + 2; 
  
    if (l < n && as(x[l].codigo) > as(x[largest].codigo)) largest = l;

    if (r < n && as(x[r].codigo) > as(x[largest].codigo)) largest = r;

    if (largest != root){
        swap(x[root], x[largest]);  // Puedes utilizar el metodo tradicional (usando un auxiliar)
        heapify(x,n,largest,key);
    }
    }

    if(key==2){
    int largest = root;
    int l = 2*root + 1;
    int r = 2*root + 2; 
  
    if (l < n && as(x[l].nombre) > as(x[largest].nombre)) largest = l;

    if (r < n && as(x[r].nombre) > as(x[largest].nombre)) largest = r;

    if (largest != root){
        swap(x[root], x[largest]);  // Puedes utilizar el metodo tradicional (usando un auxiliar)
        heapify(x,n,largest,key);
    }
    }

    if(key==3){
    int largest = root;
    int l = 2*root + 1;
    int r = 2*root + 2; 
  
    if (l < n && x[l].edad > x[largest].edad) largest = l;

    if (r < n && x[r].edad > x[largest].edad) largest = r;

    if (largest != root){
        swap(x[root], x[largest]);  // Puedes utilizar el metodo tradicional (usando un auxiliar)
        heapify(x,n,largest,key);
    }
    }

}

void ordenamiento_por_heapsort(alumno *x, int n,int key){
    for (int i = n / 2 - 1; i >= 0; i--) heapify(x,n,i,key);
  
    for (int i=n-1; i>=0; i--){
        swap(x[0], x[i]);   // Puedes utilizar el metodo tradicional (usando un auxiliar)
        heapify(x, i, 0,key);
    }
}

//d