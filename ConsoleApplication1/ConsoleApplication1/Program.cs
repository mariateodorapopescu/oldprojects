using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp1
{
    class deathstar
    {
        private string culoare;
        private string detinator;
        private string locatie;
        private int capacitate;

        public deathstar(string culoare, string detinator, string locatie, int capacitate)
        {
            this.culoare = culoare;
            this.detinator = detinator;
            this.locatie = locatie;
            this.capacitate = capacitate;
        }
        public void schimbareculoare(string culoareN)
        {
            this.culoare = culoareN;
        }
        public string getculoare()
        {
            return culoare;
        }
        public int getcapacitate()
        {
            return capacitate;
        }
        public string getdetinator()
        {
            return detinator;
        }
        public void schimbarelocatie(string locatieN)
        {
            this.locatie = locatieN;
        }
        public string getlocatie()
        {
            return locatie;
        }
        public void tragere(int timp)
        {
            this.capacitate -= timp * 5;
        }
        public void incarcare(int timp)
        {
            this.capacitate += timp * 10;
        }
    }
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Bun venit in universul Star Wars! Astazi va vom prezenta raza/planeta/nava spatiala Death Star!");
            Console.WriteLine("Datele gnerale sunt:");
            deathstar intikam = new deathstar("Gri", "Darth Vader", "Sistemul Alderaan", 100);
            Console.WriteLine("Culoarea pe care o are Death Star acum este " + intikam.getculoare());
            Console.WriteLine("Locatia planetei/navei/razei Death Star este " + intikam.getlocatie());
            Console.WriteLine("Capacitatea pe care o are Death Star acum este " + intikam.getcapacitate());
            Console.WriteLine("Detinatorul planetei/navei/razei acum este " + intikam.getdetinator());
            Console.ReadKey();
            int op;
            do
            {
                Console.WriteLine("Ce doriti sa faca Death Star?");
                Console.WriteLine("1 = Sa traga in planeta langa care se afla.");
                Console.WriteLine("2 = Sa se incarce.");
                Console.WriteLine("3 = Sa isi schimbe culoarea.");
                Console.WriteLine("4 = Sa isi schimbe locatia.");
                Console.WriteLine("5 = Sa nu faca nimic.");
                op = Convert.ToInt32(Console.ReadLine());
                switch (op)
                {
                    case 1: Console.WriteLine("Cat timp doriti sa traga in planeta (in secunde)?");
                        int timp1;
                        timp1 = Convert.ToInt32(Console.ReadLine());
                        intikam.tragere(timp1);
                        if (intikam.getcapacitate() <= 10)
                        {
                            Console.WriteLine("Mai are 10% capacitate!"); Console.ReadKey(); Console.Clear();
                            break;
                        }
                        else
                        {
                            Console.WriteLine("Mai are" + intikam.getcapacitate() + "%");
                            Console.ReadKey(); Console.Clear();
                            break;
                        }

                    case 2:
                        Console.WriteLine("Cat timp doriti sa se incarce?");
                        int timp2;
                        timp2 = Convert.ToInt32(Console.ReadLine());
                        intikam.incarcare(timp2);
                        if (intikam.getcapacitate() >= 100)
                        {
                            Console.WriteLine("S-a incarcat 100%!"); Console.ReadKey(); Console.Clear();
                            break;
                        }
                        else
                        {
                            Console.WriteLine("Mai are " + intikam.getcapacitate() + "%");
                            Console.ReadKey();
                            Console.Clear();
                            break;
                        }

                    case 3:
                        Console.WriteLine("Ce culoare vreti sa aiba Death Star?");
                        string culoarenoua = Console.ReadLine();
                        intikam.schimbareculoare(culoarenoua);
                        Console.WriteLine("Death Star are acum culoarea " + intikam.getculoare());
                        Console.ReadKey();
                        Console.Clear();
                        break;
                    case 4:
                        Console.WriteLine("In ce loc vreti sa fie Death Star?");
                        string locatienoua = Console.ReadLine();
                        intikam.schimbarelocatie(locatienoua);
                        Console.WriteLine("Death Strar este acum in " + intikam.getlocatie());
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