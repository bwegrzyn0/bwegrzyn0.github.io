---
layout: post
title: "Wyznaczanie współrzędnych węzłów Księżyca"
date: 2026-01-28
categories: Astronomia 
katex: true
---

Naszym celem jest wyznaczenie aktualnej rektascensji i deklinacji węzłów Księżyca na podstawie zdjęcia Księżyca z widocznymi gwiazdami. Wiele takich obserwacji w ciągu roku pozwoli wyznaczyć tempo precesji węzłów Księżyca.

## Wyznaczanie współrzędnych ekliptycznych Księżyca
Mając dane współrzędne Księżyca, $(\alpha, \delta)$ i nachylenie ekliptyki $\varepsilon$, możemy wyznaczyć współrzędne równikowe Księżyca w układzie współrzędnych ekliptycznych, korzystając z trójkąta sferycznego przedstawionego (schematycznie) na poniższym rysunku.

<p align="center">
<img src="/assets/images/2026-01-28/sfer1.svg" width="500" /> <br> <br>
<em>BN - biegun niebieski, BE - biegun ekliptyczny</em>
</p>

Z twierdzenia cosinusów:
\$$ \sin\beta=\cos\varepsilon\sin\delta-\sin\varepsilon\cos\delta\sin\alpha, \$$
a z twierdzenia sinusów:
\$$ \cos\lambda= \frac{\cos\alpha \cos\delta}{\cos\beta}. \$$

## Wyznaczanie współrzędnych ekliptycznych węzłów

<p align="center">
<img src="/assets/images/2026-01-28/sfer2.svg" width="500" /> 
</p>

Orbita Księżyca, która zakładamy, że jest w przybliżeniu kołowa ($e\approx 0.0549$), jest nachylona pod kątem $i$ do ekliptyki. Naszym celem jest wyznaczenie $\lambda_w$ (węzła wstępującego). Z <a href="https://en.wikipedia.org/wiki/Spherical_trigonometry#Napier's_rules_for_right_spherical_triangles" target=_blank>koła Napiera</a> dla prostokątnego trójkąta sferycznego schematycznie przedstawionego na powyższym rysunku mamy:
\$$ \sin(\lambda-\lambda_w)=\cot{i}\tan{\beta}, \$$
co wystarcza do obliczenia $\lambda_w$ znając $\lambda$, $\beta$ oraz $i$. Węzeł zstępujący będzie miał oczywiście współrzędną $\lambda_w+180\degree$. Szerokość ekliptyczna obu węzłów to z definicji $\beta=0\degree$. 

Korzystając z trójkąta sferycznego z wcześniejszego rysunku, możemy wyznaczyć rektascensję i deklinację węzłów. Z twierdzenia cosinusów:
\$$ \sin\delta_w=\cos\varepsilon\sin\beta_w+\sin\varepsilon\cos\beta_w\sin\lambda_w, \$$
co po wstawieniu $\beta=0\degree$ daje
\$$ \sin\delta_w=\sin\varepsilon\sin\lambda_w, \$$
a z twierdzenia sinusów:
\$$ \cos\alpha_w=- \frac{\cos\lambda_w\cos\beta_w}{\cos\delta_w}=- \frac{\cos\lambda_w}{\cos\delta_w}. \$$
Dla węzła zstępującego podstawiamy $\lambda_w\rightarrow \lambda_w+180\degree$, co daje nam
\$$ \sin\delta_z=-\sin\delta_w, \$$
więc $\delta_w=-\delta_z$ oraz
\$$ \cos\alpha_z=-\cos\alpha_w, \$$
więc $\alpha_z=\alpha_w+180\degree$, zatem jest on dokładnie po przeciwnej stronie sfery niebieskiej.

## Obserwacje

<p align="center">
<img src="/assets/images/2026-01-28/obs.jpg" width="500" />
<img src="/assets/images/2026-01-28/wyzn.jpg" width="500" />
</p>
Powyżej znajduje się zdjęcie, na którego podstawie wyznaczamy współrzędne Księżyca oraz jego przybliżony fragment. Na zdjęciu widzimy m. in. Plejady (M45) - bardzo blisko Księżyca, Byka, Oriona, Woźnicę, Wieloryba, fragment Perseusza. Znaleziono 2 pary gwiazd, takie, że jeśli poprowadzimy przez nie prostą, to przechodzi ona w dobrym przybliżeniu przez środek tarczy Księżyca. Ich przecięcie w atlasie będzie wtedy punktem o szukanych współrzędnych równikowych.
<p align="center">
<img src="/assets/images/2026-01-28/atlas.jpg" width="500" />
</p>
Wyznaczając współrzędne pogrubionego punktu na powyższym zdjęciu otrzymujemy:
\$$ (\alpha, \delta)=(3^h37^m, 24\degree 20'), \$$
co daje praktycznie idealną zgodność w porównaniu z danymi z programu Stellarium.

Korzystając ze wcześniejszych wzorów wyznaczamy współrzędne ekliptyczne Księżyca:
\$$ (\lambda, \beta)=(57\degree 43', 4\degree 49'), \$$
gdzie przyjąłem $\varepsilon=23\degree 26'$.

Przyjmując $i=5\degree 09'$, mamy:
\$$ \lambda_w=348\degree 23' \$$
i przekształcając układy współrzędnych:
\$$ \boxed{(\alpha_w, \delta_w)=(23^h 17^m, -4\degree 35'),} \$$
gdzie wzięliśmy wartość funkcji $\arccos$ plus $180\degree$, aby być w odpowiedniej ćwiartce układu współrzędnych. Mamy również:
\$$ \boxed{(\alpha_z, \delta_z)=(11^h 17^m, 4\degree 35').} \$$
Porównując to ze współrzędnymi Księżyca, kiedy ostatni raz znalazł się w węźle (dane z programu Stellarium), różnica w rektascensji to około $10'$, a w deklinacji $1\degree$. Tak duża rozbieżność w deklinacji może wynikać np. z przybliżenia orbity Księżyca jako okręgu, co nie jest prawdą i może wprowadzić taką niedokładność do obliczeń. Efekt precesji węzłów nie powinien grać tutaj bardzo dużej roli, biorąc pod uwagę krótki czas od ostatniego węzła oraz to, że wpływa on o wiele znaczniej na rektasencję węzłów.
