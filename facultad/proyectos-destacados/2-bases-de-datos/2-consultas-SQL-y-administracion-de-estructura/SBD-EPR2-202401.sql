-- INGENIERÍA INFORMÁTICA - SISTEMAS DE BASES DE DATOS

/* -----------------------------------------------------------------------------------------------------------------------------------
Una empresa que fabrica electrodomésticos desea mantener información acerca de los mismos, sus modelos, los comercios a los cuales 
se les vendió y los clientes que los han adquirido en esos comercios. Además se registran los reclamos que han tenido. 
Para esto decide implementar una base de datos relacional.

La información a almacenar en la misma es la siguiente:

­- La empresa produce diferentes tipos de electrodomésticos. Por ejemplo: heladeras, equipos de aire acondicionado, lavarropas, cocinas, hornos, etc. 
  Se identifican por un código interno único, nombre y clase de electrodoméstico (calefacción, refrigeración, etc.)

- De cada tipo de electrodoméstico se producen varios modelos que se identifican por un código único. Cada uno tiene diferentes prestaciones o características. 
  Se debe mantener información acerca de sus características y el tiempo de garantía medido en meses otorgado por la empresa.

- Se deben registrar las partes que componen los modelos con sus características. Una parte puede ser utilizada para varios 
  modelos. 
  Se debe indicar también, que cantidad de unidades de cada parte se utiliza en el armado de cada modelo. 

­- A medida que se van fabricando los electrodomésticos se deben ir registrando. 
  Cada electrodoméstico fabricado se identifica por un nro. de serie único. Se debe indicar el tipo de electrodoméstico, el modelo, la fecha de fabricación, 
  y si está vendido, el comercio y la fecha de venta al comercio.

- Cuando el comercio lo vende registra en nuestra base de datos los datos del cliente y la fecha de venta al mismo.

- De los comercios se requiere conocer su nombre, dirección y teléfonos. 

- De los clientes se requiere conocer su nombre y DNI.

­- Se deben registrar también las fallas de los electrodomésticos informadas por los clientes. En particular se necesita conocer el electrodoméstico, 
  el cliente, la fecha de registro de la falla, una descripción de la misma y las partes reemplazadas.

La base de datos implementada es la siguiente:
*/

drop table dbo.partes_reemplazadasss
drop table dbo.reclamosss
drop table dbo.electrodomesticosss
drop table dbo.clientesss
drop table dbo.comerciosss
drop table dbo.partes_modelosss
drop table dbo.partes_electrodomesticosss
drop table dbo.modelos_electrodomesticosss
drop table dbo.tipos_electrodomesticosss
drop table dbo.clases_electrodomesticosss

create table dbo.clases_electrodomesticosss
(
 cod_clase_electrodomestico		varchar(3)	not null,
 nom_clase_electrodomestico		varchar(40)	not null,
 constraint PK__clases_electrodomesticosss__END 
            primary key (cod_clase_electrodomestico)
)

create table dbo.tipos_electrodomesticosss
(
 cod_tipo_electrodomestico		varchar(3)	not null,
 nom_tipo_electrodomestico		varchar(40)	not null,
 cod_clase_electrodomestico		varchar(3)	not null,
 constraint PK__tipos_electrodomesticosss__END 
            primary key (cod_tipo_electrodomestico),
 constraint FK__tipos_electrodomesticosss__clases_electrodomesticosss__1__END 
            foreign key (cod_clase_electrodomestico) references dbo.clases_electrodomesticosss
)

create table dbo.modelos_electrodomesticosss
(
 cod_modelo_electrodomestico	varchar(10)		not null,
 cod_tipo_electrodomestico		varchar(3)		not null,
 caracteristicas				varchar(255)	not null,
 meses_garantia					smallint		not null,
 constraint PK__modelos_electrodomesticosss__END 
            primary key (cod_modelo_electrodomestico),
 constraint FK__modelos_electrodomesticosss__tipos_electrodomesticosss__1__END 
            foreign key (cod_tipo_electrodomestico) references dbo.tipos_electrodomesticosss,
 constraint CK__modelos_electrodomesticosss__meses_garantia__END
            check (meses_garantia > 0)
)

create table dbo.partes_electrodomesticosss
(
 cod_parte_electrodomestico		varchar(10)		not null,
 nom_parte_electrodomestico		varchar(255)	not null,
 caracteristicas				varchar(255)	not null,
 constraint PK__partes_electrodomesticosss__END 
            primary key (cod_parte_electrodomestico)
)

create table dbo.partes_modelosss
(
 cod_modelo_electrodomestico	varchar(10)		not null,
 cod_parte_electrodomestico		varchar(10)		not null,
 cantidad						tinyint			not null,
 constraint PK__partes_modelosss__END 
            primary key (cod_modelo_electrodomestico, cod_parte_electrodomestico),
 constraint FK__partes_modelos__modelos_electrodomesticosss__1__END
            foreign key (cod_modelo_electrodomestico) references dbo.modelos_electrodomesticosss,
 constraint FK__partes_modelos__partes_electrodomesticosss__1__END
            foreign key (cod_parte_electrodomestico) references dbo.partes_electrodomesticosss,
 constraint CK__partes_modelos__cantidadd__END
            check (cantidad > 0)
)

create table dbo.comerciosss
(
 nro_comercio					smallint		not null,
 nom_comercio					varchar(40)		not null,
 dir_comercio					varchar(255)	not null,
 tel_comercio					varchar(40)		not null,
 constraint PK__comerciosss__END
            primary key (nro_comercio)
)

create table dbo.clientesss
(
 nro_cliente					integer			not null,
 nom_cliente					varchar(40)		not null,
 dni_cliente					integer			not null,
 constraint PK__clientesss__END
            primary key (nro_cliente),
 constraint UK__clientesss__1__END
			unique (dni_cliente)
)

create table dbo.electrodomesticosss
(
 nro_serie						varchar(20)		not null,
 cod_modelo_electrodomestico	varchar(10)		not null,
 fecha_fabricacion				date			not null,
 nro_comercio					smallint		null,
 fecha_venta_comercio			date			null,
 nro_cliente					integer			null,
 fecha_venta_cliente			date			null,
 constraint PK__electrodomesticoss__END 
            primary key (nro_serie),
 constraint FK__electrodomesticos__modelos_electrodomesticoss__1__END
            foreign key (cod_modelo_electrodomestico) references dbo.modelos_electrodomesticosss,
 constraint FK__electrodomesticoss__comercios__1__END                                                /*ACA*/
            foreign key (nro_comercio) references dbo.comerciosss,
 constraint FK__electrodomesticos__clientes__1__END													/*ACA*/
            foreign key (nro_cliente) references dbo.clientesss,
 constraint CK__electrodomesticoss__ventas__END
            check (nro_comercio is null     and fecha_venta_comercio is null     and nro_cliente is null     and fecha_venta_cliente is null or
			       nro_comercio is not null and fecha_venta_comercio is not null and nro_cliente is null     and fecha_venta_cliente is null or
			       nro_comercio is not null and fecha_venta_comercio is not null and nro_cliente is not null and fecha_venta_cliente is not null)
)

create table dbo.reclamoss
(
 nro_reclamo					integer			not null,
 nro_serie						varchar(20)		not null,
 fecha_reclamo					date			not null,
 observaciones					varchar(255)	not null,
 constraint PK__reclamos__END
			primary key (nro_reclamo),
 constraint FK__reclamos__electrodomesticos__1__END
			foreign key (nro_serie) references dbo.electrodomesticosss
)

create table dbo.partes_reemplazadass
(
 nro_reclamo					integer			not null,
 cod_parte_electrodomestico		varchar(10)		not null,
 cantidad						tinyint			not null,
 constraint PK__partes_reemplazadas__END
            primary key (nro_reclamo, cod_parte_electrodomestico),
 constraint FK__partes_reemplazadas__reclamos__1__END
			foreign key (nro_reclamo) references dbo.reclamoss,
 constraint FK__partes_reemplazadas__partes_electrodomesticos__1__END
			foreign key (cod_parte_electrodomestico) references dbo.partes_electrodomesticosss
)

/*

1. Para tener un control más riguroso de los clientes que realizan reclamos, solamente se reciben reclamos cuando el 
   cliente está registrado como propietario del electrodoméstico.
   Por lo tanto, si un cliente transfiere el electrodoméstico a otro debe informar ese traspaso para que el nuevo cliente
   pueda realizar un reclamo.
   Se requiere realizar un cambio en el modelo de datos e implementarlo en la base de datos para poder registrar estas 
   transferencias de propiedad.
   Las mismas serán consideradas como "ventas" con lo cual un producto podrá tener varias "ventas".
   El modelo debe permitir determinar quien es el cliente que puede realizar un reclamo según la fecha del mismo. 
   
   Ud. deberá modificar el modelo e implementar los cambios migrando los datos actuales a la nueva implementación sin 
   pérdida de información. (50)



   --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
   Tener en cuenta:

   No puedo borrar todo para las nuevas modificaciones porque pierdo toda la información de la base de datos que tengo actualmente.

   Debo hacer un paso a paso para que me permita llegar a la nueva estructura de tablas que permita almacenar tanto lo nuevo como lo viejo.

   No se puede modificar el script original, es decir, ir a los datos que tengo en la base y empezar a borrar información para que se adapte a los requerimientos.

   También hay que tener en cuenta que el orden de las operaciones puede ser crítico, 
   si quiero eliminar una columna, no la puedo eliminar si tiene una regla de integridad, 
   primero debo eliminar la regla de integridad y después eliminar la columna 

   --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

   PASOS:
   Paso 1: Creo la tabla ventas que registra cada venta de un electrodoméstico

   Los atributos de esta nueva tabla van hacer: 

	* nro_venta: Número de venta (identificador único).
	* nro_serie: Número de serie del electrodoméstico (referencia a electrodomesticoss).
	* nro_cliente: Número del cliente que compra el electrodoméstico (referencia a clientess).
	* fecha_venta: Fecha de la venta.

   Paso 2: Migrar los datos a la nueva tabla recien creada
  
	* Se copian los datos de ventas existentes desde la tabla electrodomesticoss a la nueva tabla ventas.

	* Solo se migran los registros donde nro_cliente y fecha_venta_cliente no son nulos.

   Paso 3: Eliminar las reglas de integridad de la tabla electrodomesticos, para poder eliminar despues esas columnas y no tener informacion redundante en la base de datos.

   Paso 4: Posteriormente eliminamos las columnas "nro_cliente" y "fecha_venta_cliente" de la tabla electrodomesticoss.

   Paso 5: Se agrega una nueva restricción de verificación para asegurar que los campos "nro_comercio" y "fecha_venta_comercio" se manejen correctamente.

   --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

 */


/* Crear la tabla ventas */
CREATE TABLE dbo.ventasssssss (
    nro_venta INTEGER IDENTITY(1,1) PRIMARY KEY,
    nro_serie VARCHAR(20) NOT NULL,
    nro_cliente INTEGER NOT NULL,
    fecha_venta DATE NOT NULL,
    FOREIGN KEY (nro_serie) REFERENCES dbo.electrodomesticosss(nro_serie),
    FOREIGN KEY (nro_cliente) REFERENCES dbo.clientesss(nro_cliente)
);
GO

/* Migrar datos a la nueva tabla ventas */
INSERT INTO dbo.ventasssssss (nro_serie, nro_cliente, fecha_venta)
SELECT nro_serie, nro_cliente, fecha_venta_cliente
FROM dbo.electrodomesticosss
WHERE nro_cliente IS NOT NULL AND fecha_venta_cliente IS NOT NULL;
GO

/* Eliminar restricciones de la tabla electrodomesticoss */
ALTER TABLE dbo.electrodomesticosss DROP CONSTRAINT FK__electrodomesticos__clientes__1__END;
ALTER TABLE dbo.electrodomesticosss DROP CONSTRAINT CK__electrodomesticoss__ventas__END;
GO

/* Eliminar columnas de la tabla electrodomesticoss */
ALTER TABLE dbo.electrodomesticosss DROP COLUMN nro_cliente;
ALTER TABLE dbo.electrodomesticosss DROP COLUMN fecha_venta_cliente;
GO

/* Agregar nueva restricción de ventas a la tabla electrodomesticoss */
ALTER TABLE dbo.electrodomesticosss
ADD CONSTRAINT CK__electrodomesticoss__ventas__END
CHECK (
    nro_comercio IS NULL AND fecha_venta_comercio IS NULL OR
    nro_comercio IS NOT NULL AND fecha_venta_comercio IS NOT NULL
);
GO

/* Verificar la migración de datos */
SELECT * FROM dbo.ventasssssss;
GO

/* Verificar la tabla electrodomesticoss */
SELECT * FROM dbo.electrodomesticosss;
GO


 /*
2. Programar una consulta basada en el modelo original que muestre por año la cantidad de partes que se han utilizado para fabricar
   los diferentes electrodomésticos.

   Mostrar lo siguiente: (50)

   ----------------------------------------------------------------------------------------------------------
   año			cod_parte		nom_parte						cantidad
   ----------------------------------------------------------------------------------------------------------
   XXXX			XXX				XXXXXXXXXXXXXXXXXXXXXXXXXXXXX		XXX
   XXXX			XXX				XXXXXXXXXXXXXXXXXXXXXXXXXXXXX		XXX

  
*/

/* Consulta para obtener la cantidad de partes utilizadas para fabricar electrodomésticos por año */

SELECT 
    YEAR(e.fecha_fabricacion) AS año,
    pm.cod_parte_electrodomestico AS cod_parte,
    pe.nom_parte_electrodomestico AS nom_parte,
    SUM(pm.cantidad) AS cantidad
FROM 
    dbo.electrodomesticosss e
JOIN 
    dbo.modelos_electrodomesticosss me ON e.cod_modelo_electrodomestico = me.cod_modelo_electrodomestico
JOIN 
    dbo.partes_modelosss pm ON me.cod_modelo_electrodomestico = pm.cod_modelo_electrodomestico
JOIN 
    dbo.partes_electrodomesticosss pe ON pm.cod_parte_electrodomestico = pe.cod_parte_electrodomestico
GROUP BY 
    YEAR(e.fecha_fabricacion),
    pm.cod_parte_electrodomestico,
    pe.nom_parte_electrodomestico
ORDER BY 
    año, cod_parte;

