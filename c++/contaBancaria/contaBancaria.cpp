#include <iostream>
#include <string>
#include <fstream>

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
            std::cout << "Deposito bancario" << std::endl << std::endl;
            double deposito = getValor();
            int escolha = 0;

            
            if (deposito <= 0) {
                std::cout << "ERROR:valor invalido!" << std::endl << std::endl;;
            
            } else {
                std::cout << "Deposito concluido!" << std::endl << std::endl;
                this->saldo += deposito;
            }

            do {
                std::cout << "Deseja emitir comprovante: " << std::endl << "1- SIM | 2-NAO" << std::endl;
                std::cin >> escolha;
                
            } while (escolha > 1 && escolha < 0);

            if (escolha == 1) {
                emitirComprovanteDeposito(deposito);
            } 

           
        } // fim do depositarValor

        void sacarValor() {
            std::cout << "Saque bancario" << std::endl << std::endl;
            double saque = getValor();
            int escolha = 0;
            
            if (saque > this->saldo || saque <= 0) {
                std::cout  << "ERROR:saldo insuficiente ou valor invalido!" << std::endl << std::endl;
            
            } else { 
                this->saldo -= saque;
                std::cout << "Saque efetuado: " << this->nameUsuario << std::endl << std:: endl;
            }

            do {
                std::cout << "Deseja emitir comprovante: " << std::endl << "1- SIM | 2-NAO" << std::endl;
                std::cin >> escolha;
            
            } while (escolha > 1 && escolha < 0);

            if (escolha == 1) {
                emitirComprovanteSaque(saque);
            } 

        } //fim do sacarValor 

        void mostrarSaldo() {
            std::cout << this->nameUsuario << std::endl <<"Saldo disponivel: " << this->saldo << std::endl << std::endl;
        }

        void transferirValor(Conta *link2) {
            std::cout << "Transferencia bancaria" << std::endl << std::endl;
            double transferencia = getValor();
            int escolha = 0;

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

            do {
                std::cout << "Deseja emitir comprovante: " << std::endl << "1- SIM | 2-NAO" << std::endl;
                std::cin >>  escolha;
            
            } while (escolha > 1 && escolha < 0);
            

            if (escolha == 1) {
                emitirComprovanteTrasnferencia(transferencia);
            } 

        }// fim do TranferirValor

        void emitirComprovanteSaque(int saque)  {
            std::ofstream myfile;
            
            myfile.open ("Comprovante de Saque.txt");
            myfile << "Comprovante de saque: " << std::endl << this->nameUsuario << std::endl << "===============================================" <<  std::endl << "- " << saque << std::endl;
            myfile.close();
        }

        void emitirComprovanteDeposito(int deposito)  {
            std::ofstream myfile;
            
            myfile.open ("Comprovante de deposito.txt");
            myfile << "Comprovante de deposito: " << std::endl << this->nameUsuario << std::endl << "===============================================" <<  std::endl << "+ " << deposito << std::endl;
            myfile.close();
        }

        void emitirComprovanteTrasnferencia(int transferencia)  {
            std::ofstream myfile;
            
            myfile.open ("Comprovante de tranferencia.txt");
            myfile << "Comprovante de transferencia: " << std::endl << this->nameUsuario << std::endl << "===============================================" <<  std::endl << transferencia << std::endl;
            myfile.close();
        }

        double getValor() {
            double valor;
            
            do {
                std::cout << "Digite o valor: " << std::endl << std::endl;
                std::cin >> valor;
            
            } while (valor <= 0);
            return valor;
        }

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
        std::cout << "===============================================" << std::endl << std::endl;
        
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
