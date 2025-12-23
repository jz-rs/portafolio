# Aplicación Web de Procesamiento de Imágenes

**Streamlit + OpenCV + Python**

Este proyecto es una aplicación web desarrollada con **Streamlit** que permite aplicar filtros y transformaciones sobre imágenes utilizando técnicas de **procesamiento digital** con **OpenCV**.
Incluye manejo de caché, almacenamiento temporal de imágenes y un pipeline modular que facilita agregar nuevos filtros.

---

## Funcionalidades principales

* **Carga de imágenes** desde el navegador.
* **Previsualización en tiempo real** de resultados.
* Implementación de filtros como:

  * Conversión a escala de grises
  * Detección de bordes
  * Difuminado (blur)
  * Realce de contornos
  * Segmentación simple
* **Guardado automático** de imágenes procesadas.
* **Caché** para mejorar el rendimiento.
* **Tests automáticos** para asegurar la correcta ejecución del pipeline.

---

## Tecnologías utilizadas

* **Python 3**
* **Streamlit** (interfaz web)
* **OpenCV** (procesamiento de imágenes)
* **Pillow** (manejo de archivos)
* **PyTest** (tests automatizados)

---

## Cómo ejecutar el proyecto

### 1. Instalar dependencias

```
pip install -r requirements.txt
```

### 2. Ejecutar la aplicación

```
streamlit run streamlit
```

### 3. Abrir en navegador

Streamlit abrirá automáticamente la app en:
[http://localhost:8501](http://localhost:8501)

---

## Testing

El proyecto incluye pruebas con PyTest:

```
pytest
```

---

## Objetivo del proyecto

Este trabajo demuestra habilidades en:

* Programación en Python
* Procesamiento de imágenes
* Desarrollo de interfaces web
* Modularización de código
* Testing y buenas prácticas
* Manejo de caché y archivos temporales

Ideal para roles de **Data Engineer**, **Software Developer**, **Computer Vision Junior**, o **Automation**.
