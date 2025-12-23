# Procedimientos Almacenados, Triggers y Cursores

Proyecto avanzado en SQL Server que implementa lógica de integridad académica utilizando triggers, cursores y procedimientos almacenados.

## Funcionalidades desarrolladas
### 1. Control de aplazos mediante triggers
* Un alumno no puede inscribirse a un examen si superó la cantidad máxima de aplazos.
* Implementado con triggers AFTER INSERT y AFTER UPDATE.
* Uso de cursor para procesar cada fila afectada.

### 2. Migración y validación de datos
* Eliminación y re-creación de constraints.
* Control exhaustivo de estados académicos.

### 3. Procedimiento almacenado
Recibe:
* Código de materia
* Fecha de examen

Devuelve:
* Alumnos que pueden rendir en esa fecha
* Con validación de regularidad, aplazos y aprobación previa.

## Habilidades demostradas
* Uso profesional de SQL Server
* Triggers con cursor
* Procedimientos almacenados
* Integridad referencial compleja
* Consultas multi-join