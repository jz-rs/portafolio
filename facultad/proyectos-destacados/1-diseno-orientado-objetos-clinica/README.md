# **README – Sistema de Gestión para Clínica Privada (Diseño Orientado a Objetos)**

## **Descripción general**

Este proyecto corresponde al **Trabajo Integrador Final de la materia Diseño Orientado a Objetos**.
Consiste en el análisis, diseño y construcción de un sistema para la gestión interna de una **clínica privada**, abarcando pacientes, historias clínicas, turnos, órdenes de consulta, médicos, servicios y administración.

El desarrollo se realizó aplicando estrictamente los principios de **UML**, **POO**, patrones de diseño y buenas prácticas de arquitectura.
La implementación final fue construida en **Java** usando **JavaFX**, con estructura en capas (modelo, DAO, DTO y controladores).

---

# **Funcionalidades principales**

### **Módulo Recepción**

* Consultar paciente
* Registrar nuevo paciente
* Generar orden de consulta
* Asignar turno

### **Módulo Médico**

* Ver órdenes asignadas
* Registrar diagnóstico
* Registrar prácticas realizadas

### **Módulo Administrativo**

* Generar listado de caja
* Generar resumen de consultas

---

# **Arquitectura del sistema**

El proyecto está dividido en capas:

### **1. Modelo (`modelo/`)**

Clases que representan la lógica y estructura del dominio:

Incluye clases como:

* `Paciente`
* `Persona`
* `Domicilio`
* `HistoriaClinica`
* `Turno`
* `DetalleHistoriaClinica`
* `Medico`
* `Recepcionista`
* `Administrativo`
* `Servicio`
* `TipoDeConsulta`
* `OrdenDeConsulta`

**Los atributos y relaciones están documentados visualmente en los diagramas UML.**
Ver archivo: *DiagramasUML.pdf* – páginas 1 y 2.

*(Ejemplo: en página 2 se ve el diagrama de clases completo, con multiplicidades y relaciones.)* 

---

### **2. DAO (`dao/`)**

Acceso a datos mediante JDBC.

Ejemplos:

* `PacienteDao.java`

  * Buscar paciente por DNI
  * Listar pacientes
  * Registrar paciente
  * Obtener historia clínica asociada

Este DAO demuestra un manejo real de consultas SQL, joins, relaciones y construcción de objetos a partir de ResultSets.

---

### **3. DTO (`dto/`)**

Clases diseñadas para transportar datos combinados entre la UI y el DAO, como:

* `PacienteCompletoDto.java` → combina datos personales, domicilio, historia clínica y jefe de grupo familiar.

---

### **4. Controladores JavaFX (`controlador/`)**

Controlan la interfaz gráfica, por ejemplo:

* `PacienteController.java`

  * Carga tabla de pacientes
  * Mapea columnas desde DTO
  * Muestra detalles del paciente seleccionado
  * Integra vista con DAO

---

### **5. UI con JavaFX**

Ventanas construidas con FXML + CSS.

Ejemplo:

```java
FXMLLoader fxmlLoader = new FXMLLoader(App.class.getResource("MainView.fxml"));
```

Incluye:

* Tablas
* Formularios
* Estilos personalizados
* Listeners para selección de pacientes

---

# **Diagrama UML del proyecto**

Los archivos UML incluidos muestran:

### **✔ Diagrama de clases completo del dominio**

(Página 2 del PDF.) — Todas las relaciones entre Paciente, Historia Clínica, Médico, Servicio, Orden de Consulta, etc. 

### **✔ Casos de uso**

(Página 3.)

### **✔ Diagramas de secuencia y colaboración**

(Páginas 4 y 8.)

### **✔ Máquina de estados**

(Páginas 9 y 10.)

Estos diagramas son fundamentales porque muestran que el proyecto no fue solo código, sino una **ingeniería completa del sistema**, siguiendo correctamente DOO.

---

# **Tecnologías utilizadas**

* **Java 17**
* **JavaFX**
* **FXML + CSS**
* **JDBC**
* **MySQL**
* **DAO Pattern**
* **DTO Pattern**
* **UML (StarUML / Modelio / Astah)**

---

# **Puntos fuertes del proyecto**

* Diseño bien estructurado con clases, relaciones y encapsulamiento correcto.
* Uso destacado de DTO y DAO para separar capas.
* Integración funcional entre lógica, datos y UI.
* Modelado UML completo y profesional.
* Implementación realista de un entorno médico–administrativo.
* Reconstrucción de objetos complejos desde SQL (historia clínica + jefe + domicilio).

---

# **Archivos incluidos**

* `/modelo` – clases del dominio
* `/dto` – transporte de datos
* `/dao` – acceso a base de datos
* `/controlador` – lógica de interfaz
* `/styles.css`
* `/MainView.fxml`
* `DiagramasUML.pdf`
* `Documentacion.pdf` (Documento formal del trabajo)
* `README.md` (este archivo)

---

# **Cómo ejecutar**

1. Importar el proyecto en NetBeans / IntelliJ con soporte para JavaFX.
2. Configurar la base de datos MySQL según los scripts incluidos.
3. Ajustar las credenciales en `ConexionSql.java`.
4. Ejecutar desde `App.java`.

---

# **Resumen final**

Este proyecto demuestra capacidad para:

* Diseñar un sistema completo usando UML.
* Implementar un backend estructurado en capas.
* Crear interfaces gráficas funcionales en JavaFX.
* Manejar SQL real con relaciones múltiples.
* Aplicar POO correctamente en un caso realista.
* Documentar todo el proceso con estándares profesionales.