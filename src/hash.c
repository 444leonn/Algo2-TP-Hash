#include "hash.h"
#include "constantes.h"

#include <stdlib.h>

typedef struct par {
    char *clave;
	void *valor;
} par_t;

typedef struct nodo
{
	struct par par;
	struct nodo *siguiente;
} nodo_t;

struct hash {
	struct nodo **tabla;
	size_t cantidad;
	size_t factor_carga;
};

hash_t *hash_crear(size_t capacidad_inicial)
{
	hash_t *hash = calloc(1, sizeof(hash_t));
	if (hash == NULL)
		return NULL;

	if (capacidad_inicial < CAPACIDAD_MINIMA)
		hash->tabla = malloc(CAPACIDAD_MINIMA * sizeof(nodo_t*));

	hash->tabla = malloc(capacidad_inicial * sizeof(nodo_t*));

	return hash;
}

size_t hash_cantidad(hash_t *hash)
{
	if (hash == NULL)
		return 0;

	return hash->cantidad;
}

bool hash_insertar(hash_t *hash, char *clave, void *valor, void **encontrado);

void *hash_buscar(hash_t *hash, char *clave);

bool hash_contiene(hash_t *hash, char *clave);

void *hash_quitar(hash_t *hash, char *clave);

size_t hash_iterar(hash_t *hash, bool (*f)(char *, void *, void *), void *ctx);

void hash_destruir(hash_t *hash);

void hash_destruir_todo(hash_t *hash, void (*destructor)(void *));
