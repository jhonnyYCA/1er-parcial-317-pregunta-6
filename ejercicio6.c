#include "stdio.h"
#include "mpi.h"



int main(){
	
	int tag=0;
	MPI_Status estado;
	int nro_procesadores;
	int nro_ejecuta;
	char nombre_procesadores[MPI_MAX_PROCESSOR_NAME];
	int len_nombre;
	
	
	
	MPI_Init(NULL, NULL);
	MPI_Comm_size(MPI_COMM_WORLD, &nro_procesadores);
	MPI_Comm_rank(MPI_COMM_WORLD, &nro_ejecuta);
	MPI_Get_processor_name(nombre_procesadores, &len_nombre);
	
	//printf("%s %d %d \n",nombre_procesadores, nro_procesadores, nro_ejecuta);

	
	int i;
		
	int a=0;
	int b=1;
	int fibo;


	if(nro_ejecuta==0){
				
		
		MPI_Send(&a, 1, MPI_INT, 1, tag, MPI_COMM_WORLD);
		MPI_Send(&b, 1, MPI_INT, 1, tag, MPI_COMM_WORLD);
			
		
	}
	for (i=0;i<15;i++){
		if(nro_ejecuta==1){
			MPI_Recv(&a, 1, MPI_INT,MPI_ANY_SOURCE, tag, MPI_COMM_WORLD, &estado);
			MPI_Recv(&b, 1, MPI_INT,MPI_ANY_SOURCE, tag, MPI_COMM_WORLD, &estado);
			
			
			printf("proce 2 %d\n",a);
			fibo=a+b;
			a=b;
			b=fibo;
			
						
			MPI_Send(&a, 1, MPI_INT, 2, tag, MPI_COMM_WORLD);
			MPI_Send(&b, 1, MPI_INT, 2, tag, MPI_COMM_WORLD);
			
				
		}
		if(nro_ejecuta==2){
			MPI_Recv(&a, 1, MPI_INT, MPI_ANY_SOURCE, tag, MPI_COMM_WORLD, &estado);
			MPI_Recv(&b, 1, MPI_INT, MPI_ANY_SOURCE, tag, MPI_COMM_WORLD, &estado);
			
		
			
			printf("proce 3 %d\n",a);
			fibo=a+b;
			a=b;
			b=fibo;
			
			MPI_Send(&a, 1, MPI_INT, 1, tag, MPI_COMM_WORLD);
			MPI_Send(&b, 1, MPI_INT, 1, tag, MPI_COMM_WORLD);
			
				
		}
	}
	
	
	MPI_Finalize();
	
	
	return 0;	
	
}
