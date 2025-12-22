# Análisis de Ventas – Adventure Works

Proyecto de análisis de datos desarrollado con **Excel** y **Power BI**, basado en el caso empresarial ficticio “Adventure Works”.  
El objetivo es analizar el rendimiento de ventas, entender por qué los resultados del último año fueron menores a lo esperado y proponer acciones de mejora.

---

## Contenido del repositorio

Este proyecto incluye:

- Informe completo del proceso analítico (`Apunte y trabajo.pdf`)
- Archivo de visualización y modelado en Power BI (`AWXLSPBI.pbix`)
- Archivos Excel utilizados como fuente de datos:
  - `product.xlsx`
  - `Region.xlsx`
  - `Reseller.xlsx`
  - `sales.xlsx`
  - `Salesperson.xlsx`
  - `SalespersonRegion.xlsx`

---

## Objetivo del análisis

Identificar:

- Qué productos y categorías venden más o menos.
- Qué regiones aportan mayor volumen de ventas.
- Qué revendedores y vendedores tienen mejor rendimiento.
- Oportunidades de mejora para aumentar la rentabilidad.

---

## Metodología aplicada

El proyecto sigue un ciclo de vida completo de analítica de datos de 10 etapas:

### 1. Comprensión del negocio  
Se definió el problema principal:  
**Las ventas del año anterior fueron menores a lo esperado.**  
Se establecieron preguntas clave para analizar causas y oportunidades.

### 2. Enfoque analítico  
Se eligió un enfoque **descriptivo y diagnóstico**, usando métricas de ventas, ganancias y rentabilidad.

### 3. Requisitos de datos  
Se identificaron todas las tablas y columnas necesarias: productos, regiones, revendedores, vendedores y ventas.

### 4. Recopilación de datos  
Los datos se obtuvieron desde 6 archivos de Excel proporcionados por el dataset.

### 5. Comprensión de datos  
Se estudiaron:
- tipos de variables  
- distribución  
- relaciones entre tablas  
- posibles problemas de calidad

### 6. Preparación de datos  
Incluyó:
- limpieza  
- normalización  
- unificación de claves  
- validación de datos  
- creación de una tabla calendario  

### 7. Modelado en Power BI  
Se construyó un **modelo relacional** con relaciones entre:
- Ventas ↔ Productos  
- Ventas ↔ Regiones  
- Ventas ↔ Revendedores  
- Ventas ↔ Vendedores  
- Vendedores ↔ SalespersonRegion  
- Calendario ↔ Ventas  

### 8. Medidas DAX utilizadas  
Ejemplos de cálculos del análisis:

DAX
Ganancia = SUM(Sales[Sales]) - SUM(Sales[Cost])

Rentabilidad = [Ganancia] / SUM(Sales[Sales])

Ventas Totales = SUM(Sales[Sales])

Costo Total = SUM(Sales[Cost])

### 9. Visualización en Power BI

Se generaron gráficos y dashboards:

* Ventas por categoría
* Ganancias por categoría
* Ventas por país
* Ganancias por país
* Rentabilidad por categoría
* Rentabilidad por país
* Segmentadores por año, país y categoría

### 10. Evaluación y conclusiones

Principales resultados:

* **Componentes** es la categoría con mayores ventas.
* **Bikes** es la categoría más rentable.
* **Estados Unidos** lidera ventas y ganancias.
* Algunas categorías presentan baja rentabilidad → oportunidad de mejora.

---

## Principales aprendizajes

Este proyecto demuestra manejo de:

* Modelado relacional
* Limpieza e integración de datos
* Power BI (DAX, relaciones, dashboards)
* Análisis descriptivo y diagnóstico
* Construcción de informes ejecutivos
* Razonamiento basado en datos para la toma de decisiones