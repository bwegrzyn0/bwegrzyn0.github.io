---
layout: post
title: "Tworzenie prostej symulacji grawitacji w C++, część 2: Rysowanie kół, planety"
date: 2025-07-13
categories: [Programowanie]
katex: true
---

## Rysowanie kół
Aby obserwować interakcję grawitacyjną, potrzebujemy obiekty, które będą w taki sposób oddziaływać. W tej symulacji będą one nazywane planetami, chociaż nie będą miały ściśle określonego przedziału na masę, gęstość i rozmiary. Będziemy je traktować jak kule, czyli w tym wypadku tak samo, jak masy punktowe. Aby reprezentować je na ekranie, będzie konieczna możliwość rysowania kół. Niestety SDL nie posiada funkcji wykonującej takie zadanie, więc trzeba ją stworzyć samodzielnie.

Wydajnym algorytmem do rysowania kół i okręgów jest <a href="https://en.wikipedia.org/wiki/Midpoint_circle_algorithm" target="_blank">algorytm midpoint</a>. Jego implementację dla SDL znalazłem <a href="https://gist.github.com/Gumichan01/332c26f6197a432db91cc4327fcabb1c" target="_blank">tutaj</a>.

W funkcji `draw()` przeniesionej do osobnego pliku dodałem następujące linijki rysujące okrąg i koło:
```cpp
SDL_RenderDrawCircle(renderer, 300, 300, 100);
SDL_RenderFillCircle(renderer, 300, 500, 100);
```
Rezultat jest następujący:
<p align="center">
<img src="/assets/images/2025-07-13/okrag-i-kolo-test.png" width="500" />
</p>

## Planety
### Obiekt planeta
W pliku `planet.h` utworzyłem klasę `Planet`, a w niej potrzebne zmienne i funkcje.
```cpp
#ifndef PLANET_H
#define PLANET_H
class Planet {
    public:
        // położenie planety
        float x;
        float y;
        // prędkość planety
        float v_x;
        float v_y;
        // masa planety
        float mass;
        // gęstość planety
        float density;
        // promień planety 
        float radius;
        // przyspieszenie planety
        float a_x;
        float a_y;
        // indentyfikator
        float ID;
        // konstruktor
        Planet(float _x, float _y, float _v_x, float _v_y, float _mass, float _density, float _ID);
        // funkcja aktualizująca położenie planety
        void updatePos();
};
#endif
```
Identyfikator będzie potrzebny do obliczania przyspieszenia.

Następnie w pliku `planet.cpp` utworzyłem konstruktor, w którym obliczam promień na podstawie masy i gęstości ze wzoru
\$$R = \left(\frac{3M}{4\pi\rho}\right)^{1/3}\$$
```cpp
Planet::Planet(float _x, float _y, float _v_x, float _v_y, float _mass, float _density, float _ID) {
    // przyporządkowujemy zmienne lokalne przekazane do konstruktora zmiennym globalnym 		
    x = _x;
    y = _y;
    v_x = _v_x;
    v_y = _v_y;
    mass = _mass;
    density = _density;
    ID = _ID; 
    a_x = 0;
    a_y = 0;
    // R = [3M/(4*PI*rho)]^(1/3) dla jednorodnej kuli
    radius = pow((double) (3.0f*mass/(4.0f*3.1415f*density)), 0.333d);
}
```
W funkcji `updatePos()` zaimplementowałem proste obliczanie kolejnych położeń i prędkości planety za pomocą algorytmu Eulera. 
```cpp
void Planet::updatePos() {
    std::vector<Planet> planets) {
        // OBLICZANIE POŁOŻENIA
        x += v_x * dT;
        // dT to krok czasowy zdefiniowany w pliku main.h
        y += v_y * dT;

        // OBLICZANIE PRĘDKOŚCI
        // musimy zresetować przyspieszenie, aby obliczyć je na nowo
        a_x = 0;
        a_y = 0;

        // obliczanie przyspieszenia ...

        // aktualizujemy prędkość
        v_x += a_x * dT;
        v_y += a_y * dT;
    }
```

$dT$ to pewien krok czasowy ustalony w pliku `main.h`. W przyszłości zostanie zaimplementowany algorytm Rungego-Kutty.

Ponieważ krok czasowy jest stały, w przypadku spowolnienia działania programu, zostanie również spowolniona symulacja. Rozważmy to na przykładzie. Załóżmy że program działa z szybkością 60 klatek na sekundę. Wtedy w ciągu sekundy przy kroku czasowym równym $1/60\text{s}$ symulacja postąpi o $1\text{s}$. Jeśli program będzie działał z szybkością 30 klatek na sekundę, aby w tym samym czasie symulacja postąpiła o czas $1\text{s}$, krok czasowy musiałby być 2 razy dłuższy.
Zostanie to w przyszłości naprawione implementując inną postać pętli programu.

### Zarządzanie planetami
Aby sprawnie zarządzać wszystkimi obiektami utworzyłem plik `handler.cpp`, którego zadaniem będzie aktualizowanie wszystkich planet. W nim utworzyłem wektor ze wszystkimi planetami i funkcję, która będzie je aktualizować.
```cpp
void updatePlanets() {
	for (int i = 0; i < planets.size(); i++) {
		planets.at(i).updatePos();	
	}
}
```
Warto zauważyć, że nie zadziała tutaj pętla for each, ponieważ tworzy ona nowe obiekty planet i aktualizuje parametry tych nowych, a nie już istniejących obiektów.

W pliku `main.cpp` utworzyłem funkcję:
```cpp
void setupEnvironment() {
    planets.push_back(*(new Planet(200, 300, 0, 5.47, 0.001, 1, 1)));
    planets.push_back(*(new Planet(595, 300, 0, -4, 30, 500, 1)));
    planets.push_back(*(new Planet(400, 300, 0, 0.033, 200, 1000, 2)));
}
```
oraz dodałem `updatePlanets()` z `handler.cpp` do pętli.

Należy pamiętać, aby wyświetlać planety na ekranie, dlatego zmodyfikowałem funkcję `draw()` w następujący sposób:
```cpp
void draw(SDL_Renderer* renderer) {
    // ustal kolor tła i je zapełń
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    // renderujemy po kolei wszystkie planety
    for (int i = 0; i < planets.size(); i++) {
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderFillCircle(renderer, (int) planets.at(i).x, (int) planets.at(i).y, (int) (planets.at(i).radius * 100));
    }

    // wyświetl to, co zostało narysowane 
    SDL_RenderPresent(renderer);
}
```

### Interakcja grawitacyjna
Potrzebujemy w funkcji `updatePlanets()` dostęp do wektora `planets`, więc będzie on przekazywany jako argument tej funkcji. Następnie utwórzmy w niej pętlę sumującą przyspieszenia pochodzące od wszystkich innych planet, aby obliczyć siłę wypadkową. Oczywiście musimy sumować rzuty przyspieszeń na poszczególne osie.
```cpp
for (int i = 0; i < planets.size(); i++) {
    if (planets.at(i).ID != ID) { // nie chcemy żeby planeta przyciągała sama siebie
        // obliczamy r^2
        float distance_squared = (x - planets.at(i).x)*(x - planets.at(i).x)+(y - planets.at(i).y)*(y - planets.at(i).y);
        // obliczamy wartość przyspieszenia
        float a = G*planets.at(i).mass/distance_squared;
        // obliczamy wartość sinusa i cosinusa kąta między planetami
        float cos = (planets.at(i).x-x)/pow((double) distance_squared, 0.5d);
        float sin = (planets.at(i).y-y)/pow((double) distance_squared, 0.5d);
        // dodajemy składowe przyspieszenia
        a_x += a*cos;
        a_y += a*sin;
    }
}
```

## Poruszanie kamerą
Planety mogą szybko uciec z pola widzenia, dlatego ważna jest możliwość poruszania kamerą. 

Utworzyłem tablicę boolów `keysDown` o 4 elementach, które opisują stan wciśnięcia strzałek na klawiaturze. Są one ustalane w funkcji `handleEvents()` w `main.cpp`. Na ich podstawie mogę zmieniać aktualną prędkość i położenie kamery: 
```cpp
void updateCam() {
    // ustawiamy prędkość kamery na postawie wciśniętych klawiszy
    if (keysDown[0])
        cam_vy = -cam_v;
    else if (keysDown[1])
        cam_vy = cam_v;
    else 
        cam_vy = 0;
    if (keysDown[2])
        cam_vx = cam_v;
    else if (keysDown[3])
        cam_vx = -cam_v;
    else 
        cam_vx = 0;
    // aktualizujemy położenie kamery
    cam_x += cam_vx;
    cam_y += cam_vy;
}
```
`cam_v` to pewna odgórnie ustalona (później dostępna do regulacji dla użytkownika) prędkość kamery.
Aby zmiana położenia kamery miała efekt, jej położenie musimy odjąć od położenia planet:
```cpp
SDL_RenderFillCircle(renderer, (int) planets.at(i).x - cam_x, (int) planets.at(i).y - cam_y, (int) (planets.at(i).radius * 100));
```
Dlaczego tak jest? Załóżmy, że planeta jest w pozycji $(200, 200)$, a kamera w pozycji $(100, 100)$. Oznacza to, że planeta jest o $100$ pikseli niżej i o $100$ pikseli na prawo od kamery. Położenie planety na ekranie powinno zatem wynosić $(100, 100)$, a więc $(200, 200)-(100,100)$.

W chwili obecnej program prezentuje się następująco:
<p align="center">
<img src="/assets/images/2025-07-13/dzialanie-programu.gif" width=500/>
</p>

W następnej części zostanie zaimplementowana ulepszona pętla programu oraz algorytm Rungego-Kutty do obliczania trajektorii planet. Kod źródłowy projektu jest dostępny na <a href="https://github.com/bwegrzyn0/grav-sim" target="_blank">GitHub</a>.
