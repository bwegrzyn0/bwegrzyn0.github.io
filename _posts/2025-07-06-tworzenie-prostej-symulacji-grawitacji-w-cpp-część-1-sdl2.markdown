---
layout: post
title: "Tworzenie prostej symulacji grawitacji w C++, część 1: SDL2"
date: 2025-07-06
categories: [Programowanie]
katex: true
---

## Cel projektu
Celem tego projektu jest stworzenie programu w C++, który będzie pozwalał użytkownikowi:
- dodawać do sceny ciała niebieskie, które będą oddziaływać ze sobą grawitacyjnie
- modyfikować ich parametry, takie jak masa, prędkość, położenie, jasność itd. za pomocą prostego interfejsu
- pauzować, przyspieszać, cofać, resetować symulację
- poruszać się kamerą po scenie za pomocą myszki, przybliżać i oddalać widok
- wykreślać i przewidywać trajektorie obiektów
- ustalać punkt odniesienia dla trajektorii
- zablokować widok na jednym obiekcie.

Program ma spełniać również następujące założenia:
- ruch planet ma być dokładnie obliczany za pomocą algorytmu Rungego-Kutty (opisanego w <a href="/programowanie/numeryczne-rozwiązywanie-równań-różniczkowych-2-rzędu-metodą-rungego-kutty" target="_blank">tym</a> artykule)
- program ma być zoptymalizowany
- ruch będzie odbywał się w jednej płaszczyźnie i przedstawiany będzie widok z góry
- oświetlenie planet, zaćmienia (gdy jedna planeta przechodzi za drugą)
- planety będą przedstawiane jako koła o różnych kolorach 
- anti-aliasing planet
- zarządzanie obiektami w kodzie powinno być łatwe i uporządkowane.

## Kod źródłowy
Kod źródłowy projektu jest dostępny w <a href="https://github.com/bwegrzyn0/grav-sim" target="_blank">repozytorium GitHub</a>.

## Wyświetlanie okna - SDL2
Do wyświetlania okna i rysowania na nim w tym projekcie użyłem bibliotekę <a href="https://www.libsdl.org/" target="_blank">SDL2</a>. Dobry poradnik, jak ją używać, można znaleźć <a href="https://lazyfoo.net/tutorials/SDL/index.php" target="_blank">tutaj</a>.

### Inicjalizacja SDL
W pliku ```main.cpp``` dodałem bibliotekę SDL2:
```cpp
#include <SDL2/SDL.h>
```
a następnie utworzyłem zmienne i obiekty:
```cpp
// wymiary okna
const int WIDTH = 800;
const int HEIGHT = 600;

// okno
SDL_Window* window = NULL;
// renderer
SDL_Renderer* renderer = NULL;
```
Obiekt ```renderer``` będzie odpowiedzialny za rysowanie pikseli w oknie ```window```. Stworzyłem funkcję inicjalizującą SDL:
```cpp
// funkcja odpowiadająca za inicjalizację SDL
bool init() {
	bool success = true;
	// inicjalizuj SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		printf("Could not init SDL: %s\n", SDL_GetError());
		success = false;
	} else {
		// utwórz okno
		window = SDL_CreateWindow("grav-sim", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN);
		if (window == NULL) {
			printf("Could not create window: %s\n", SDL_GetError());
			success = false;
		} else {
			// stwórz renderer
			renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
			if (renderer == NULL) {
				printf("Could not create renderer: %s\n", SDL_GetError());
				success = false;
			}
		}

	}
	return success;
}
```
Jeśli inicjalizacja nie przebiegnie pomyślnie, funkcja zwróci ```false```. Potrzebna jest również funkcja "sprzątająca" po wszystkim:
```cpp
// funkcja odpowiadająca za "posprzątanie" po wszystkim
void close() {
	// zniszcz okno, zwolnij miejsce w pamięci, zamknij SDL
	SDL_DestroyWindow(window);
	window = NULL;
	SDL_Quit();
}
```

### Rejestrowanie wejścia od użytkownika
W tym celu utworzyłem obiekt ```SDL_Event```, który będzie wykrywał zdarzenia, takie jak wciśnięcie klawiatury, myszki itd. oraz funkcję, która na podstawie wykrytego zdarzenia wypisze informację do konsoli:
```cpp
bool running = true;
SDL_Event event;

void handleEvents() {
    while(SDL_PollEvent(&event)) { // funkcja sprawdzająca zdarzenia
        switch(event.type) { // typ zdarzenia
            case SDL_KEYDOWN:
                printf("Key press\n"); // wciśnięcie klawisza na klawiaturze
                break;
            case SDL_KEYUP:
                printf("Key up\n"); // puszczenie klawisza na klawiaturze
                break;
            case SDL_QUIT:
                running = false; // zamknięcie okna
                printf("Quitting\n");
                break;
            default:
                break;
        }
    }
}
```
Zmienna ```running``` mówi, czy program jest uruchomiony. Przyda się ona w jednym z kolejnych kroków.

### Rysowanie
Utworzyłem funkcję, która będzie odpowiedzialna za rysowanie na ekranie. Dodałem w niej również rysowanie białego prostokąta:
```cpp
void draw() {
	SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255); // ustawiamy kolor tła (RGBA)
	SDL_RenderClear(renderer); // zapełniamy tło

	SDL_Rect rect; // tworzymy nowy obiekt typu prostokąt
	rect.x = 100; // ustalamy jego położenie i rozmiary
	rect.y = 100;
	rect.w = 100;
	rect.h = 100;

	SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF); // ustawiamy kolor prostokąta
	SDL_RenderFillRect(renderer, &rect); // rysujemy wypełniony prostokąt

	SDL_RenderPresent(renderer); // wyświetlamy obraz na ekranie
}
```

### Pętla programu
Utworzyłem funkcję zawierającą główną pętlę programu:
```cpp
void loop() {
	while (running) {
		handleEvents();
		draw();
	}
}
```
Na razie kod jest uruchamiany w pętli while, czyli jak najszybciej jest to możliwe. Jest to oczywiście nieopłacalne i niestabilne. Zostanie to naprawione później.

Tak wygląda moja funkcja ```main()```:
```cpp
int main(int argc, char* argv[]) {
	if (!init()) {
		return 1;
	}
	loop();
	close();
	return 0;
}
```

## Co dalej?
Powyższy program wyświetla okno, a w nim biały prostokąt na czerwonym tle. W następnej części opiszę proces rysowania kół i okręgów za pomocą algorytmu midpoint oraz to, jak dodałem planety.
