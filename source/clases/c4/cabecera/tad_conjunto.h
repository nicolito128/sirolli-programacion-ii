#ifndef TAD_CONJUNTO
#define TAD_CONJUNTO

// Declaración de la estructura de datos
typedef short int *tipo_conjunto;

// Declaración de las operaciones
void iniciar(tipo_conjunto);
void insertar(tipo_conjunto, char);
void eliminar(tipo_conjunto);
void mostrar(tipo_conjunto);
short int pertenece(tipo_conjunto, char);
short int iguales(tipo_conjunto, tipo_conjunto);
tipo_conjunto union_conj(tipo_conjunto, tipo_conjunto);
tipo_conjunto inter_conj(tipo_conjunto, tipo_conjunto);
tipo_conjunto difer_conj(tipo_conjunto, tipo_conjunto);

#endif