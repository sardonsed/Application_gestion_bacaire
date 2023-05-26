#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Classe Compte Bancaire
class CompteBancaire {
public:
    // Constructeur
    CompteBancaire(string nom, double solde_initial) : nom_(nom), solde_(solde_initial) {}

    // Méthode de dépôt
    void depot(double montant) {
        solde_ += montant;
    }

    // Méthode de retrait
    void retrait(double montant) {
        solde_ -= montant;
    }

    // Méthode pour obtenir le solde
    double get_solde() {
        return solde_;
    }

    // Méthode pour obtenir le nom du titulaire du compte
    string get_nom() {
        return nom_;
    }

private:
    string nom_;        // Nom du titulaire du compte
    double solde_;      // Solde du compte
};

// Classe Banque
class Banque {
public:
    // Constructeur
    Banque(string nom) : nom_(nom) {}

    // Méthode pour ajouter un compte bancaire
    void ajouter_compte(CompteBancaire compte) {
        comptes_.push_back(compte);
    }

    // Méthode pour obtenir le nombre de comptes bancaires dans la banque
    int get_nombre_comptes() {
        return comptes_.size();
    }

    // Méthode pour obtenir le solde total de tous les comptes dans la banque
    double get_solde_total() {
        double total = 0;
        for (int i = 0; i < comptes_.size(); i++) {
            total += comptes_[i].get_solde();
        }
        return total;
    }

    // Méthode pour afficher les informations de tous les comptes bancaires dans la banque
    void afficher_informations() {
        cout << "Informations sur les comptes bancaires de la banque " << nom_ << ":" << endl;
        for (int i = 0; i < comptes_.size(); i++) {
            cout << "Titulaire : " << comptes_[i].get_nom() << " - Solde : " << comptes_[i].get_solde() << endl;
        }
    }

private:
    string nom_;                        // Nom de la banque
    vector<CompteBancaire> comptes_;    // Liste des comptes bancaires dans la banque
};

// Fonction principale
int main() {
    // Création d'une banque
    Banque ma_banque("Ma banque");

    // Création de quelques comptes bancaires
    CompteBancaire compte1("John Doe", 1000);
    CompteBancaire compte2("Jane Doe", 5000);
    CompteBancaire compte3("Bob Smith", 200);

    // Ajout des comptes à la banque
    ma_banque.ajouter_compte(compte1);
    ma_banque.ajouter_compte(compte2);
    ma_banque.ajouter_compte(compte3);

    // Affichage des informations de tous les comptes bancaires dans la banque
    ma_banque.afficher_informations();

    // Effectuer des opérations sur les comptes bancaires
    compte
