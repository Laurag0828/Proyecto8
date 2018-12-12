#include <stdio.h>//Funciones basicas de entrada salida
#include "Cuestionarios.h"
#include "Preguntas.h"
#include "Opciones.h"

int testdata(){

    FILE *f;

    remove("Cuestionarios.txt");
    remove("Preguntas.txt");
    remove("Opciones.txt");

    struct Cuestionario cuestionario1 = {"01","Evaluación suma", "Matemáticas", 5, 1,"0000123"};
    struct Cuestionario cuestionario2 = {"02","Evaluación multiplicación", "Matemáticas", 5, 1,"0000123"};
    struct Cuestionario cuestionario3 = {"03","Evaluación resta", "Matemáticas", 5, 1,"0000123"};
    struct Cuestionario cuestionario4 = {"04","Evaluación unidad I", "Español", 4, 1,"0000123"};
    struct Cuestionario cuestionario5 = {"05","Evaluación tema I Historia Mundial", "Historia", 3, 1,"0000123"};

    f=fopen("Cuestionarios.txt","a");

    fwrite(&cuestionario1, sizeof(cuestionario1),1,f);
    fwrite(&cuestionario2, sizeof(cuestionario2),1,f);
    fwrite(&cuestionario3, sizeof(cuestionario3),1,f);
    fwrite(&cuestionario4, sizeof(cuestionario4),1,f);
    fwrite(&cuestionario5, sizeof(cuestionario5),1,f);


    fclose(f);

    struct Pregunta pregunta11 = {"01","001","Cuanto es 4 + 9?", 3, 20,"0000123"};
    struct Pregunta pregunta12 = {"01","002","Cuanto es 14 + 7?", 3, 20,"0000123"};
    struct Pregunta pregunta13 = {"01","003","Cuanto es 23 + 5?", 3, 20,"0000123"};
    struct Pregunta pregunta14 = {"01","004","Cuanto es 27 + 12?", 3, 20,"0000123"};
    struct Pregunta pregunta15 = {"01","005","Cuanto es 28 + 19?", 3, 20,"0000123"};

    struct Pregunta pregunta21 = {"02","001","Cuanto es 4 * 9?", 3, 20,"0000123"};
    struct Pregunta pregunta22 = {"02","002","Cuanto es 14 * 7?", 3, 20,"0000123"};
    struct Pregunta pregunta23 = {"02","003","Cuanto es 23 * 5?", 3, 20,"0000123"};
    struct Pregunta pregunta24 = {"02","004","Cuanto es 27 * 12?", 3, 20,"0000123"};
    struct Pregunta pregunta25 = {"02","005","Cuanto es 28 * 19?", 3, 20,"0000123"};

    struct Pregunta pregunta31 = {"03","001","Cuanto es 9 - 4?", 3, 20,"0000123"};
    struct Pregunta pregunta32 = {"03","002","Cuanto es 14 - 7?", 3, 20,"0000123"};
    struct Pregunta pregunta33 = {"03","003","Cuanto es 23 - 5?", 3, 20,"0000123"};
    struct Pregunta pregunta34 = {"03","004","Cuanto es 27 - 12?", 3, 20,"0000123"};
    struct Pregunta pregunta35 = {"03","005","Cuanto es 28 - 19?", 3, 20,"0000123"};

    struct Pregunta pregunta41 = {"04","001","Venimos a clase _______ la mañana.", 3, 25,"0000123"};
    struct Pregunta pregunta42 = {"04","002","Tenemos dos libros _______.", 3, 25,"0000123"};
    struct Pregunta pregunta43 = {"04","003","A mí me ______ los animales.", 3, 25,"0000123"};
    struct Pregunta pregunta44 = {"04","004","¿______ hermanos tienes?", 3, 25,"0000123"};

    struct Pregunta pregunta51 = {"05","001","En que año terminó la II Guerra mundial?", 3, 25,"0000123"};
    struct Pregunta pregunta52 = {"05","002","En que año alunizó el apolo 11?", 3, 25,"0000123"};
    struct Pregunta pregunta53 = {"05","003","En que año fué inaugurado el canal de Panamá", 3, 50,"0000123"};

    f=fopen("Preguntas.txt","a");

    fwrite(&pregunta11, sizeof(pregunta11),1,f);
    fwrite(&pregunta12, sizeof(pregunta12),1,f);
    fwrite(&pregunta13, sizeof(pregunta13),1,f);
    fwrite(&pregunta14, sizeof(pregunta14),1,f);
    fwrite(&pregunta15, sizeof(pregunta15),1,f);

    fwrite(&pregunta21, sizeof(pregunta21),1,f);
    fwrite(&pregunta22, sizeof(pregunta22),1,f);
    fwrite(&pregunta23, sizeof(pregunta23),1,f);
    fwrite(&pregunta24, sizeof(pregunta24),1,f);
    fwrite(&pregunta25, sizeof(pregunta25),1,f);

    fwrite(&pregunta31, sizeof(pregunta31),1,f);
    fwrite(&pregunta32, sizeof(pregunta32),1,f);
    fwrite(&pregunta33, sizeof(pregunta33),1,f);
    fwrite(&pregunta34, sizeof(pregunta34),1,f);
    fwrite(&pregunta35, sizeof(pregunta35),1,f);

    fwrite(&pregunta41, sizeof(pregunta41),1,f);
    fwrite(&pregunta42, sizeof(pregunta42),1,f);
    fwrite(&pregunta43, sizeof(pregunta43),1,f);
    fwrite(&pregunta44, sizeof(pregunta44),1,f);

    fwrite(&pregunta51, sizeof(pregunta51),1,f);
    fwrite(&pregunta52, sizeof(pregunta52),1,f);
    fwrite(&pregunta53, sizeof(pregunta53),1,f);

    fclose(f);

    struct Opcion opcion111 = {"01","001",'a',"15",0,"0000123"};
    struct Opcion opcion112 = {"01","001",'b',"11",0,"0000123"};
    struct Opcion opcion113 = {"01","001",'c',"13",1,"0000123"};
    struct Opcion opcion114 = {"01","001",'d',"17",0,"0000123"};
    struct Opcion opcion115 = {"01","001",'e',"49",0,"0000123"};

    struct Opcion opcion121 = {"01","002",'a',"22",0,"0000123"};
    struct Opcion opcion122 = {"01","002",'b',"19",0,"0000123"};
    struct Opcion opcion123 = {"01","002",'c',"23",0,"0000123"};
    struct Opcion opcion124 = {"01","002",'d',"21",1,"0000123"};
    struct Opcion opcion125 = {"01","002",'e',"18",0,"0000123"};

    struct Opcion opcion131 = {"01","003",'a',"28",1,"0000123"};
    struct Opcion opcion132 = {"01","003",'b',"29",0,"0000123"};
    struct Opcion opcion133 = {"01","003",'c',"23",0,"0000123"};
    struct Opcion opcion134 = {"01","003",'d',"30",0,"0000123"};
    struct Opcion opcion135 = {"01","003",'e',"32",0,"0000123"};

    struct Opcion opcion141 = {"01","004",'a',"40",0,"0000123"};
    struct Opcion opcion142 = {"01","004",'b',"41",0,"0000123"};
    struct Opcion opcion143 = {"01","004",'c',"37",0,"0000123"};
    struct Opcion opcion144 = {"01","004",'d',"39",1,"0000123"};
    struct Opcion opcion145 = {"01","004",'e',"36",0,"0000123"};

    struct Opcion opcion151 = {"01","005",'a',"40",0,"0000123"};
    struct Opcion opcion152 = {"01","005",'b',"47",1,"0000123"};
    struct Opcion opcion153 = {"01","005",'c',"44",0,"0000123"};
    struct Opcion opcion154 = {"01","005",'d',"39",0,"0000123"};
    struct Opcion opcion155 = {"01","005",'e',"52",0,"0000123"};

    struct Opcion opcion211 = {"02","001",'a',"43",0,"0000123"};
    struct Opcion opcion212 = {"02","001",'b',"41",0,"0000123"};
    struct Opcion opcion213 = {"02","001",'c',"36",1,"0000123"};
    struct Opcion opcion214 = {"02","001",'d',"34",0,"0000123"};
    struct Opcion opcion215 = {"02","001",'e',"49",0,"0000123"};

    struct Opcion opcion221 = {"02","002",'a',"92",0,"0000123"};
    struct Opcion opcion222 = {"02","002",'b',"99",0,"0000123"};
    struct Opcion opcion223 = {"02","002",'c',"93",0,"0000123"};
    struct Opcion opcion224 = {"02","002",'d',"98",1,"0000123"};
    struct Opcion opcion225 = {"02","002",'e',"88",0,"0000123"};

    struct Opcion opcion231 = {"02","003",'a',"115",1,"0000123"};
    struct Opcion opcion232 = {"02","003",'b',"105",0,"0000123"};
    struct Opcion opcion233 = {"02","003",'c',"125",0,"0000123"};
    struct Opcion opcion234 = {"02","003",'d',"145",0,"0000123"};
    struct Opcion opcion235 = {"02","003",'e',"120",0,"0000123"};

    struct Opcion opcion241 = {"02","004",'a',"314",0,"0000123"};
    struct Opcion opcion242 = {"02","004",'b',"304",0,"0000123"};
    struct Opcion opcion243 = {"02","004",'c',"334",0,"0000123"};
    struct Opcion opcion244 = {"02","004",'d',"324",1,"0000123"};
    struct Opcion opcion245 = {"02","004",'e',"364",0,"0000123"};

    struct Opcion opcion251 = {"02","005",'a',"533",0,"0000123"};
    struct Opcion opcion252 = {"02","005",'b',"513",1,"0000123"};
    struct Opcion opcion253 = {"02","005",'c',"503",0,"0000123"};
    struct Opcion opcion254 = {"02","005",'d',"523",0,"0000123"};
    struct Opcion opcion255 = {"02","005",'e',"543",0,"0000123"};

    struct Opcion opcion311 = {"03","001",'a',"6",0,"0000123"};
    struct Opcion opcion312 = {"03","001",'b',"4",0,"0000123"};
    struct Opcion opcion313 = {"03","001",'c',"5",1,"0000123"};
    struct Opcion opcion314 = {"03","001",'d',"7",0,"0000123"};
    struct Opcion opcion315 = {"03","001",'e',"8",0,"0000123"};

    struct Opcion opcion321 = {"03","002",'a',"7",1,"0000123"};
    struct Opcion opcion322 = {"03","002",'b',"9",0,"0000123"};
    struct Opcion opcion323 = {"03","002",'c',"11",0,"0000123"};
    struct Opcion opcion324 = {"03","002",'d',"8",0,"0000123"};
    struct Opcion opcion325 = {"03","002",'e',"10",0,"0000123"};

    struct Opcion opcion331 = {"03","003",'a',"17",0,"0000123"};
    struct Opcion opcion332 = {"03","003",'b',"19",0,"0000123"};
    struct Opcion opcion333 = {"03","003",'c',"21",0,"0000123"};
    struct Opcion opcion334 = {"03","003",'d',"18",1,"0000123"};
    struct Opcion opcion335 = {"03","003",'e',"20",0,"0000123"};

    struct Opcion opcion341 = {"03","004",'a',"16",0,"0000123"};
    struct Opcion opcion342 = {"03","004",'b',"19",0,"0000123"};
    struct Opcion opcion343 = {"03","004",'c',"18",0,"0000123"};
    struct Opcion opcion344 = {"03","004",'d',"15",1,"0000123"};
    struct Opcion opcion345 = {"03","004",'e',"17",0,"0000123"};

    struct Opcion opcion351 = {"03","005",'a',"10",0,"0000123"};
    struct Opcion opcion352 = {"03","005",'b',"9",1,"0000123"};
    struct Opcion opcion353 = {"03","005",'c',"14",0,"0000123"};
    struct Opcion opcion354 = {"03","005",'d',"7",0,"0000123"};
    struct Opcion opcion355 = {"03","005",'e',"11",0,"0000123"};

    struct Opcion opcion411 = {"04","001",'a',"por",1,"0000123"};
    struct Opcion opcion412 = {"04","001",'b',"de",0,"0000123"};
    struct Opcion opcion413 = {"04","001",'c',"en",0,"0000123"};

    struct Opcion opcion421 = {"04","002",'a',"azules",1,"0000123"};
    struct Opcion opcion422 = {"04","002",'b',"azul",0,"0000123"};
    struct Opcion opcion423 = {"04","002",'c',"blanca",0,"0000123"};

    struct Opcion opcion431 = {"04","003",'a',"gusto",0,"0000123"};
    struct Opcion opcion432 = {"04","003",'b',"gustan",1,"0000123"};
    struct Opcion opcion433 = {"04","003",'c',"gusta",0,"0000123"};

    struct Opcion opcion441 = {"04","004",'a',"Quién",0,"0000123"};
    struct Opcion opcion442 = {"04","004",'b',"Cuántos",1,"0000123"};
    struct Opcion opcion443 = {"04","004",'c',"Dónde",0,"0000123"};

    struct Opcion opcion511 = {"05","001",'a',"1946",0,"0000123"};
    struct Opcion opcion512 = {"05","001",'b',"1944",0,"0000123"};
    struct Opcion opcion513 = {"05","001",'c',"1945",1,"0000123"};

    struct Opcion opcion521 = {"05","002",'a',"1969",1,"0000123"};
    struct Opcion opcion522 = {"05","002",'b',"1968",0,"0000123"};
    struct Opcion opcion523 = {"05","002",'c',"1971",0,"0000123"};

    struct Opcion opcion531 = {"05","003",'a',"1912",0,"0000123"};
    struct Opcion opcion532 = {"05","003",'b',"1914",1,"0000123"};
    struct Opcion opcion533 = {"05","003",'c',"1916",0,"0000123"};


    f=fopen("Opciones.txt","a");

    fwrite(&opcion111, sizeof(opcion111),1,f);
    fwrite(&opcion112, sizeof(opcion112),1,f);
    fwrite(&opcion113, sizeof(opcion113),1,f);
    fwrite(&opcion114, sizeof(opcion114),1,f);
    fwrite(&opcion115, sizeof(opcion115),1,f);

    fwrite(&opcion121, sizeof(opcion121),1,f);
    fwrite(&opcion122, sizeof(opcion122),1,f);
    fwrite(&opcion123, sizeof(opcion123),1,f);
    fwrite(&opcion124, sizeof(opcion124),1,f);
    fwrite(&opcion125, sizeof(opcion125),1,f);

    fwrite(&opcion131, sizeof(opcion131),1,f);
    fwrite(&opcion132, sizeof(opcion132),1,f);
    fwrite(&opcion133, sizeof(opcion133),1,f);
    fwrite(&opcion134, sizeof(opcion134),1,f);
    fwrite(&opcion135, sizeof(opcion135),1,f);

    fwrite(&opcion141, sizeof(opcion141),1,f);
    fwrite(&opcion142, sizeof(opcion142),1,f);
    fwrite(&opcion143, sizeof(opcion143),1,f);
    fwrite(&opcion144, sizeof(opcion144),1,f);
    fwrite(&opcion145, sizeof(opcion145),1,f);

    fwrite(&opcion151, sizeof(opcion151),1,f);
    fwrite(&opcion152, sizeof(opcion152),1,f);
    fwrite(&opcion153, sizeof(opcion153),1,f);
    fwrite(&opcion154, sizeof(opcion154),1,f);
    fwrite(&opcion155, sizeof(opcion155),1,f);

    fwrite(&opcion211, sizeof(opcion211),1,f);
    fwrite(&opcion212, sizeof(opcion212),1,f);
    fwrite(&opcion213, sizeof(opcion213),1,f);
    fwrite(&opcion214, sizeof(opcion214),1,f);
    fwrite(&opcion215, sizeof(opcion215),1,f);

    fwrite(&opcion221, sizeof(opcion221),1,f);
    fwrite(&opcion222, sizeof(opcion222),1,f);
    fwrite(&opcion223, sizeof(opcion223),1,f);
    fwrite(&opcion224, sizeof(opcion224),1,f);
    fwrite(&opcion225, sizeof(opcion225),1,f);

    fwrite(&opcion231, sizeof(opcion231),1,f);
    fwrite(&opcion232, sizeof(opcion232),1,f);
    fwrite(&opcion233, sizeof(opcion233),1,f);
    fwrite(&opcion234, sizeof(opcion234),1,f);
    fwrite(&opcion235, sizeof(opcion235),1,f);

    fwrite(&opcion241, sizeof(opcion241),1,f);
    fwrite(&opcion242, sizeof(opcion242),1,f);
    fwrite(&opcion243, sizeof(opcion243),1,f);
    fwrite(&opcion244, sizeof(opcion244),1,f);
    fwrite(&opcion245, sizeof(opcion245),1,f);

    fwrite(&opcion251, sizeof(opcion251),1,f);
    fwrite(&opcion252, sizeof(opcion252),1,f);
    fwrite(&opcion253, sizeof(opcion253),1,f);
    fwrite(&opcion254, sizeof(opcion254),1,f);
    fwrite(&opcion255, sizeof(opcion255),1,f);

    fwrite(&opcion311, sizeof(opcion311),1,f);
    fwrite(&opcion312, sizeof(opcion312),1,f);
    fwrite(&opcion313, sizeof(opcion313),1,f);
    fwrite(&opcion314, sizeof(opcion314),1,f);
    fwrite(&opcion315, sizeof(opcion315),1,f);

    fwrite(&opcion321, sizeof(opcion321),1,f);
    fwrite(&opcion322, sizeof(opcion322),1,f);
    fwrite(&opcion323, sizeof(opcion323),1,f);
    fwrite(&opcion324, sizeof(opcion324),1,f);
    fwrite(&opcion325, sizeof(opcion325),1,f);

    fwrite(&opcion331, sizeof(opcion331),1,f);
    fwrite(&opcion332, sizeof(opcion332),1,f);
    fwrite(&opcion333, sizeof(opcion333),1,f);
    fwrite(&opcion334, sizeof(opcion334),1,f);
    fwrite(&opcion335, sizeof(opcion335),1,f);

    fwrite(&opcion341, sizeof(opcion341),1,f);
    fwrite(&opcion342, sizeof(opcion342),1,f);
    fwrite(&opcion343, sizeof(opcion343),1,f);
    fwrite(&opcion344, sizeof(opcion344),1,f);
    fwrite(&opcion345, sizeof(opcion345),1,f);

    fwrite(&opcion351, sizeof(opcion351),1,f);
    fwrite(&opcion352, sizeof(opcion352),1,f);
    fwrite(&opcion353, sizeof(opcion353),1,f);
    fwrite(&opcion354, sizeof(opcion354),1,f);
    fwrite(&opcion355, sizeof(opcion355),1,f);

    fwrite(&opcion411, sizeof(opcion411),1,f);
    fwrite(&opcion412, sizeof(opcion412),1,f);
    fwrite(&opcion413, sizeof(opcion413),1,f);

    fwrite(&opcion421, sizeof(opcion421),1,f);
    fwrite(&opcion422, sizeof(opcion422),1,f);
    fwrite(&opcion423, sizeof(opcion423),1,f);

    fwrite(&opcion431, sizeof(opcion431),1,f);
    fwrite(&opcion432, sizeof(opcion432),1,f);
    fwrite(&opcion433, sizeof(opcion433),1,f);

    fwrite(&opcion441, sizeof(opcion441),1,f);
    fwrite(&opcion442, sizeof(opcion442),1,f);
    fwrite(&opcion443, sizeof(opcion443),1,f);

    fwrite(&opcion511, sizeof(opcion511),1,f);
    fwrite(&opcion512, sizeof(opcion512),1,f);
    fwrite(&opcion513, sizeof(opcion513),1,f);

    fwrite(&opcion521, sizeof(opcion521),1,f);
    fwrite(&opcion522, sizeof(opcion522),1,f);
    fwrite(&opcion523, sizeof(opcion523),1,f);

    fwrite(&opcion531, sizeof(opcion531),1,f);
    fwrite(&opcion532, sizeof(opcion532),1,f);
    fwrite(&opcion533, sizeof(opcion533),1,f);

    fclose(f);

    return 0;
}
