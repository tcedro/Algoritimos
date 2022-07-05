#include <iostream>
#include <string>

class Conta {

    private:
        Conta *link;
        double saldo;
        std::string nameUsuario; 
        
    public:  
        Conta() {
            this->link = nullptr;
            this->saldo = 0;  
        } //fim do contructor padrao

        Conta(Conta *link, double saldo, std::string nameUsuario) {
            this->link = link;
            this->saldo = saldo;
            this->nameUsuario = nameUsuario;
        } //fim do contructor padrao

        void depositarValor() {
            double deposito = 0.0;
            std::cout << "Valor a ser depositado: " << std::endl << std::endl;
            std::cin >> deposito;
            if (deposito <= 0) {
                std::cout << "ERROR:valor invalido!" << std::endl << std::endl;;
            
            } else {
                std::cout << "Deposito concluido!" << std::endl << std::endl;
                this->saldo += deposito;
            }
           
        } // fim do depositarValor

        void sacarValor() {
            double saque = 0;
            
            std::cout << "Valor a ser sacado: " << std::endl << std::endl;
            std::cin >> saque;
            
            if (saque > this->saldo || saque <= 0) {
                std::cout  << "ERROR:saldo insuficiente ou valor invalido!" << std::endl << std::endl;
            
            } else { 
                this->saldo -= saque;
                std::cout << "Saque efetuado: " << this->nameUsuario << std::endl << std:: endl;
            }
        } //fim do sacarValor 

        void mostrarSaldo() {
            std::cout << this->nameUsuario << std::endl <<"Saldo disponivel: " << this->saldo << std::endl << std::endl;
        }

        void transferirValor(Conta *link2) {

            double transferencia;
            
            std::cout << "Valor da tranferencia: " << std::endl << std::endl;
            std::cin >> transferencia;

            if (transferencia > this->saldo || transferencia == 0) {
                std::cout << "ERROR:saldo insuficiente ou valor invalido!" << std::endl << std::endl;
            
            } else {
                if (link2 == nullptr) {
                    std::cout  << "ERROR:conta nao existe!" << std::endl << std::endl;
                
                } else {
                    std::cout << this->nameUsuario << " tranferencia concluida para: " << link2->nameUsuario << std::endl << std::endl;
                    this->saldo -= transferencia;
                    link2->saldo += transferencia;
                }
            }
            
        }// fim do TranferirValor

};

void menuBancario(Conta *link, Conta *link2) {
    int opcao = 0;

    
    do {
        std::cout << "====================BANK=======================" << std::endl;
        std::cout <<  "1- Mostrar Saldo disponivel" << std::endl;
        std::cout <<  "2- Sacar valor" << std::endl;
        std::cout <<  "3- Depositar" << std::endl;
        std::cout <<  "4- Transferir" << std::endl << std::endl;
        std::cout <<  "0- SAIR" << std::endl << std::endl;
        std::cin >> opcao;

        std::cout << std::endl << std::endl;

        switch (opcao) {
        case 0:
            std::cout << "Saindo..." << std::endl << std::endl;
            exit(1);
            break;

        case 1:
            link->mostrarSaldo();
            break;

        case 2:
            link->sacarValor();
            break;

        case 3:
            link->depositarValor();
            break;

        case 4:
            //falta implementação;
            link->transferirValor(link2);
            break;
    
        default:
            break;
        }

    } while (opcao > 0);

    
}


int main() {
    Conta *a = new Conta(a, 3132.2, "Marcos");
    Conta *b = new Conta(b, 150.3, "Paulo");
    
    
    
    menuBancario(a, b);
    
}