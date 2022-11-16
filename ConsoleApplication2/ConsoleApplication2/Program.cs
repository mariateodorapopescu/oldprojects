using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ConsoleApplication1
{
    class Planeta
    {
        private string culoare;
        private int marime;
        private string locatie;
        private string nume;

        public Planeta(string culoare, int marime, string locatie, string nume)
        {
            this.culoare = culoare;
            this.marime = marime;
            this.locatie = locatie;
            this.nume = nume;

        }

        public void schimbareculoare(string culoareN)
        {
            this.culoare = culoareN;
        }
        public string getculoare()
        {
            return culoare;
        }

        public void schimbarenume(string numeN)
        {
            this.nume = numeN;
        }
        public string getnume()
        {
            return nume;
        }

        public void schimbarelocatie(string locatieN)
        {
            this.culoare = locatieN;
        }
        public string getlocatie()
        {
            return locatie;
        }

        public void marire(int proportie)
        {
            this.marime = marime * proportie;
        }

        public void micsorare(int proportie)
        {
            this.marime = marime / proportie;
        }
        
        public int getmarime()
        {
            return marime;
        }

        class Program
        {
            static void Main(string[] args)
            {
                Console.WriteLine("Bun venit in aplicatia de construit si modificat planete!");
                Console.WriteLine("Haideti sa construim o planeta!");
                Planeta planetamea = new Planeta("culoare", 0, "locatie", "nume");
                Console.WriteLine("Ce culoare vreti sa aiba planeta?");
                planetamea.culoare = Console.ReadLine();
                Console.WriteLine("Ce dimensiune vreti sa aiba planeta(in milioane de km^2)?");
                planetamea.marime = Convert.ToInt32(Console.ReadLine());
                Console.WriteLine("Unde vreti sa fie planeta?");
                planetamea.locatie = Console.ReadLine();
                Console.WriteLine("Cum vreti sa se numeasca planeta?");
                planetamea.nume = Console.ReadLine();
                Console.WriteLine("Acestea fiind spuse, datele generale sunt:");
                Console.WriteLine("Planeta are culoarea {0}", planetamea.getculoare());
                Console.WriteLine("Suprafata planetei este {0} milioane de km^2" , planetamea.getmarime());
                Console.WriteLine("Locatia planetei acum este {0}", planetamea.getlocatie());
                Console.WriteLine("Numele planetei acum este {0}", planetamea.getnume());
                Console.ReadKey();
                Console.Clear();
                int op;
                do
                {
                    Console.WriteLine("Ce doriti sa faca planeta?");
                    Console.WriteLine("1 = Sa isi schimbe culoarea.");
                    Console.WriteLine("2 = Sa isi schimbe dimensiunea.");
                    Console.WriteLine("3 = Sa isi schimbe locatia.");
                    Console.WriteLine("4 = Sa isi schimbe numele.");
                    Console.WriteLine("5 = Sa nu faca nimic.");
                    op = Convert.ToInt32(Console.ReadLine());
                    switch (op)
                    {
                        case 1:
                            Console.WriteLine("Ce culoare vreti sa aiba planeta?");
                            string culoarenoua = Console.ReadLine();
                            planetamea.schimbareculoare(culoarenoua);
                            Console.WriteLine("Planeta are acum culoarea {0}" , planetamea.getculoare());
                            Console.ReadKey();
                            Console.Clear();
                            break;

                        case 2:
                                Console.WriteLine("Doriti sa se micsoreze (m) sau sa se mareasca(M)?");
                                string ceva;
                                ceva = Console.ReadLine();
                                if (ceva == "m")
                                {
                                    Console.WriteLine("De cate ori vreti sa se micsoreze planeta?");
                                    int proportie;
                                    proportie = Convert.ToInt32(Console.ReadLine());
                                    planetamea.micsorare(proportie);
                                if (planetamea.marime == 0)
                                {
                                    Console.WriteLine("Planeta nu mai exista de mica ce e!");
                                    op = 5;
                                    Console.WriteLine("Iesire");                                    
                                }
                                Console.ReadKey(); Console.Clear();
                                    break;
                                }
                                else
                                {
                                    Console.WriteLine("De cate ori vreti sa se mareasca planeta?");
                                    int proportie;
                                    proportie = Convert.ToInt32(Console.ReadLine());
                                    planetamea.marire(proportie);
                                    Console.WriteLine("Planeta are acum dimensiunea de {0} milioane de km^2", planetamea.getmarime());
                                    Console.ReadKey(); Console.Clear();
                                    break;
                                }

                        case 3:
                            Console.WriteLine("Ce locatie vreti sa aiba planeta?");
                            string locatienoua = Console.ReadLine();
                            planetamea.schimbarelocatie(locatienoua);
                            Console.WriteLine("Planeta este acum in {0} " , planetamea.getlocatie());
                            Console.ReadKey();
                            Console.Clear();
                            break;

                        case 4:
                            Console.WriteLine("Ce nume vreti sa aiba planeta?");
                            string numenou = Console.ReadLine();
                            planetamea.schimbarenume(numenou);
                            Console.WriteLine("Planeta are acum numele {0} " + planetamea.getnume());
                            Console.ReadKey();
                            Console.Clear();
                            break;

                        case 5: Console.WriteLine("Iesire"); break;
                        default: Console.WriteLine("Optiune gresita"); break;
                    }
                }
                while (op != 5);
                Console.ReadLine();

            }
        }
    }
}
