---
layout: post
title: "Symulacja dyfrakcji na okrągłej szczelinie"
date: 2026-06-05
old: true
katex: true
image: "/assets/images/2026-06-05/rys5.png" 

---

## Wprowadzenie

Rozważmy okrągłą szczelinę o promieniu $R$ wykonaną w płaszczyźnie, która w ogóle nie przepuszcza światła. Amplitudę drgań pola elektrycznego (lub magnetycznego, z dokładnością co do stałej) w każdym punkcie obrazu wytworzonego przez falę płaską padającą na szczelinę, na równoległym do płaszczyzny ekranie znajdującym się w odległości $L$ można obliczyć korzystając z reguły Huygensa. Każdy punkt szczeliny emituje do przodu falę kulistą o tej samej fazie i tej samej amplitudzie (ponieważ fala płaska jest jednorodna, a szczelina w każdym swoim punkcie przepuszcza całość światła). Ponieważ układ ma symetrię sferyczną, wprowadzimy kąt $\theta$ oraz wielkości $r'$ i $r$. Jak widzimy z rysunku, z twierdzenia Pitagorasa i twierdzenia cosinusów, $\rho=\sqrt{r^2+r'^2-2rr'\cos\theta}$. 

<p align="center">
<img src="/assets/images/2026-06-05/rys1.svg" width="500" />
</p>

Przyczynek amplitudy od punktu o współrzędnych $(r', \theta)$ dla punktu odległego od środka ekranu o $r$ to
\$$ dA = \frac{C}{\rho} e^{ik\rho}, \$$
gdzie $C$ to pewna stała, a $k=2\pi/\lambda$ to liczba falowa. Czynnik $1/\rho$ wynika z faktu, że w taki sposób maleje amplituda fali pola elektrycznego od punktowego źródła. Zakładamy ponadto, że padająca fala jest spolaryzowana liniowo, a zmianę amplitudy wynikającą z rzutowania wektora pola elektrycznego uznajemy za pomijalną, więc pole traktujemy jak skalar. Sumaryczny efekt od wszystkich przyczynków to
\$$ A = C \int \frac{1}{\rho} e^{ik\rho} dS, \$$
gdzie powierzchnią całkowania jest szczelina. Ze względu na geometrię szczeliny i wprowadzone współrzędne, $dS= r' dr' d\theta$, więc
\$$ A = C \int_0^{2\pi} \int_0^{R} \frac{1}{\rho} e^{ik\rho} r dr' d\theta. \$$
Powyższą całkę obliczymy numerycznie, istnieją jednak przybliżenia takie jak:
- **dyfrakcja Fresnela** (w bliskim polu) - przybliżamy, że wszystkie promienie są równoległe, lecz w rozwinięciu wyrażenia na $\rho$ w szereg zachowujemy tylko pierwszy wyraz:
\$$ \rho \approx L + \frac{r^2+r'^2-2rr'\cos\theta}{2L}. \$$
- **dyfrakcja Fraunhofera** (w dalekim polu) - podobnie jak wcześniej, pozostawiamy tylko pierwszy wyraz szeregu, ale również stosujemy przybliżenie $r' \ll r$, skąd \$$ \rho \approx L + \frac{r^2-2rr'\cos\theta}{2L}. \$$

Naszym celem będzie wyznaczenie najoptymalniejszych rozmiarów szczeliny do aparatu otworkowego, czyli takich, przy których plamka będąca obrazem nieskończenie dalekiego źródła punktowego ma najmniejszy rozmiar. Naszymi danymi są $f$, czyli odległość ekranu od szczeliny, oraz $\lambda$, czyli długość fali światła.

## Obliczenia numeryczne

Do obliczeń numerycznych wykorzystamy język Julia, który pozwala na łatwe operacje na liczbach zespolonych. Pierwsza z funkcji to wyrażenie podcałkowe:
```julia
function integrand(R, R0, theta0) 
	dst = r(R, R0, theta0)
	return 1/dst * exp(im * k * dst) * R0
end
```
`r(R, R0, theta0)` to funkcja zwracająca odległość $\rho$, a zmienne z zerem są odpowiednikami nieprimowanych zmiennych. `im` to jednostka urojona. Obydwie całki obliczymy za pomocą [metody Simpsona](#uzupełnienie-metoda-simpsona). Wewnętrzna całka to:
```julia
function integral_1(R, theta0)
	val = 0
	first_integrand = integrand(R, 0, theta0)
	middle_integrand = integrand(R, dR0 / 2, theta0)
	for i = 1:N_samples_R
		# metoda simpsona kwadratowa
		last_integrand = integrand(R, i * dR0, theta0)
		val += dR0 / 6 * (first_integrand + 4 * middle_integrand + last_integrand)
		first_integrand = last_integrand
		middle_integrand = integrand(R, dR0 * (i + 1/2), theta0)
	end
	return val
end
```
gdzie fist, last i middle oznaczają wartości funkcji dla $a$, $(a+b)/2$ oraz $b$. Zewnętrzną obliczamy podobnie:
```julia
function integral_2(R)
	val = 0
	first_integrand = integral_1(R, 0)
	middle_integrand = integral_1(R, dtheta0 / 2)
	for i = 1:N_samples_theta0
		last_integrand = integral_1(R, i * dtheta0)
		val += (first_integrand + 4 * middle_integrand + last_integrand) * dtheta0 / 6 
		first_integrand = last_integrand
		middle_integrand = integral_1(R, dtheta0 * (i + 1/2))
	end
	return abs2(val)
end
```
Zwracamy kwadrat modułu wartości całki, ponieważ jest wprost proporcjonalny do średniego natężenia światła dla odległości `R` od środka ekranu.

Aby wyznaczyć rozmiar plamki dla danego promienia szczeliny `r`, obliczymy maksymalną wartość natężenia światła, a następnie będziemy szukać ostatniego miejsca, dla którego natężenie wynosi $0.1\times$maksimum. Realizuje to poniższy kod:
```julia
function spot_size(r)
	# aktualizuj wartość r i krok do obliczania całki
	update_r(r)

	# liczba promieni do próbkowania
	samplesR = 50
	x = range(0, r * 2, samplesR)
	# obraz dla tych promieni
	val = [integral_2(a) for a=x]
	# maksymalna wartość
	max = maximum(val)
	
	last_i = length(val) - 1
	# czy znaleziono granicę jasnego obszaru
	ableToFind = false

	# szukamy kiedy jasność spada ostatni raz poniżej 0.1 maksimum
	for i in 2:(length(val))
		if (val[i] <= max * 0.1 && val[i-1] >= max * 0.1)
			last_i = i
			ableToFind = true
		end
	end

	# jesli takiego miejsca nie znaleziono w przedziale (0, 2r) to idziemy dalej
	iterator = last_i
	step = r * 2 / samplesR
	lastValue = val[last_i] 
	while !ableToFind
		currentValue = integral_2(iterator * step)
		if (currentValue <= max * 0.1 && lastValue >= max * 0.1)
			last_i = iterator
			ableToFind = true
		end
		lastValue = currentValue
		iterator += 1
	end
	return last_i * step
end
```
Szukamy najpierw, czy takie miejsce istnieje w przedziale od $0$ do $2\times$promień, a jeśli nie, to idziemy dalej, aż takie miejsce znajdziemy. Powyższą funkcję uruchamiamy dla różnych wartości `radius`, aby otrzymać następujący wykres zależności rozmiarów plamki od promienia szczeliny:
<p align="center">
<img src="/assets/images/2026-06-05/rys4.svg" width="500" />
</p>
Obserwujemy wyraźne minimum, które wyznacza optymalne rozmiary szczeliny. Okazuje się również, że w minimum $r_o \approx 0.7 r$, gdzie $r_o$ oraz $r$ to odpowienio promień plamki i szczeliny. Oznacza to, że szczelina skupia delikatnie światło. 

Możemy zobaczyć jak wygląda obraz na ekranie dla optymalnego promienia szczeliny:
<p align="center">
<img src="/assets/images/2026-06-05/rys5.png" width="500" />
</p>
Biały okrąg reprezentuje szczelinę. Wyraźnie widzimy, że światło zostało skupione.

Widzimy, że w granicy $r\to 0$ zależność $r_o(r)$ to w przybliżeniu $1/r$, co jest oczekiwane dla dyfrakcji Fraunhofera. Dla pierwszego minimum mamy 
\$$ \lambda = D\sin\theta = 2r\sin\theta, \$$
a $r_o \approx f\sin\theta$, więc
\$$ r_o \approx \frac{f\lambda}{2r}.\$$
Z kolei, gdy $r\gg r_o$, dążymy do optyki geometrycznej i $r_o = r$, co wyjaśnia liniowy wzrost. Możemy oszacować $r_o$ przyrównując obydwa równania:
\$$ r \approx \frac{f\lambda}{2r}, \$$
skąd
\$$ r\approx 0.71\sqrt{f\lambda}. \$$

Chcielibyśmy sprawdzić numerycznie, czy zależność $D(f, \lambda)$ ma podobną postać. Z tego powodu obliczono $D$ dla różnych wartości $f$ przy stałym $\lambda$ i na odwrót. Wykresy przedstawiały zależność prawdopodobnie potęgową, czyli:
\$$ D(f) = A_f f^\alpha \$$ 
oraz
\$$ D(\lambda) = A_\lambda \lambda^\beta. \$$
Jeśli weźmiemy w powyższych równaniach obstronnie logarytm naturalny, otrzymamy zależność postaci $y=ax+b$, gdzie $a$ to potęga, a $b$ to $\ln$ stałego współczynnika. Poniższe wykresy wykazują liniową zależność między logartymami, a więc przybliżenie potęgowe jest dobre.
<p align="center">
<img src="/assets/images/2026-06-05/rys2.svg" width="500" />
</p>
<p align="center">
<img src="/assets/images/2026-06-05/rys3.svg" width="500" />
</p>
Widzimy, że obydwa współczynniki są bliskie $1/2$, więc mamy zależność postaci $D(f,\lambda)=A\sqrt{f\lambda}$. Ponadto,
\$$ D(f)=A\sqrt{f\lambda}=A_\lambda\sqrt{f} \$$
dla ustalonego $\lambda$, co daje $A=1.34$ (wszystkie obliczenia są prowadzone w mm, lecz $A$ jest bezwymiarowe). Podobnie mamy dla $A_f$, skąd $A=1.07$. Biorąc średnią, $A=1.21\pm 0.14$. Mamy zatem
\$$ D(f) \approx 1.21 \sqrt{f\lambda}. \$$
Przykładowo dla aparatu o $f=30$mm oraz dla światła widzialnego średnio $\lambda=550$nm mamy $D=0.16$mm. Zauważmy również, że zależność ta jest bardzo podobna do tej wyprowadzonej wcześniej.


## Uzupełnienie: Metoda Simpsona
Jak powszechnie wiadomo, prostą i stosunkowo dokładną metodą pierwszego rzędu do obliczania całek jest metoda trapezów, dla której całkę
\$$ \int_a^b f(x)\,dx \$$
przybliżamy jako
\$$ \approx \frac{f(b)+f(a)}{2}(b-a), \$$
czyli przez pole trapezu utworzonego przez oś $x$, proste $x=a$ oraz $x=b$ i prostą łączącą punkty $(a, f(a))$, $(b, f(b))$. W metodzie Simpsona nie korzystamy z prostej, a z paraboli, do której dopasowania wykorzystujemy punkty $(a, f(a))$, $((a+b)/2, f((a+b)/2))$ oraz $(b, f(b))$. Po bardzo żmudnych, lecz prostych obliczeniach można wykazać, że pole pod tą parabolą to:
\$$ \int_a^b f(x)\,dx \approx \frac{b-a}{6}\left(f(a)+4f\left( \frac{a+b}{2}\right)+f(b)\right). \$$
