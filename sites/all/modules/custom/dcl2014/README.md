
QUERY ONE - PLACES


    PREFIX rdfs: <http://www.w3.org/2000/01/rdf-schema#>
    PREFIX o: <http://dbpedia.org/ontology/>
    PREFIX foaf: <http://xmlns.com/foaf/0.1/>
    PREFIX geo: <http://www.w3.org/2003/01/geo/wgs84_pos#>
    SELECT ?subject ?label ?lat ?long ?pop ?thumb ?comment ?abstract ?link
    WHERE
    {
      ?subject a o:PopulatedPlace ;
      rdfs:label ?label ;
      rdfs:comment ?comment ;
      o:abstract ?abstract ;
      o:thumbnail ?thumb  ;
      o:isPartOf  <http://dbpedia.org/resource/England>
      OPTIONAL { ?subject o:populationTotal ?pop } .
      OPTIONAL { ?subject foaf:homepage ?link } .
      OPTIONAL { ?subject geo:lat ?lat } .
      OPTIONAL { ?subject geo:long ?long } .
      FILTER (langMatches(lang(?abstract), "en")) .
      FILTER (langMatches(lang(?comment), "en")) .
      FILTER (langMatches(lang(?label), "en")) .
    }
    GROUP BY ?subject
    ORDER BY DESC(?pop)
    LIMIT 500



QUERY TWO - PEOPLE



    PREFIX rdfs: <http://www.w3.org/2000/01/rdf-schema#>
    PREFIX o: <http://dbpedia.org/ontology/>
    PREFIX foaf: <http://xmlns.com/foaf/0.1/>
    PREFIX geo: <http://www.w3.org/2003/01/geo/wgs84_pos#>
    SELECT ?subject ?label ?b ?link ?img ?comment ?abstract
    WHERE
    {
      ?subject a foaf:Person .
      ?subject rdfs:label ?label .
      ?subject o:birthPlace ?b .
      ?subject rdfs:comment ?comment .
      ?subject o:abstract ?abstract .
      ?b  o:isPartOf  <http://dbpedia.org/resource/England>
      OPTIONAL { ?subject o:thumbnail ?img } .
      OPTIONAL { ?subject foaf:homepage ?link } .
      FILTER (langMatches(lang(?label), "en")) .
      FILTER (langMatches(lang(?abstract), "en")) .
      FILTER (langMatches(lang(?comment), "en")) .
    }
    GROUP BY ?subject
    LIMIT 500

