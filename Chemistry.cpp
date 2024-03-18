#include "Chemistry_utils.h"

std::vector<Chemistry::Ion> FailedIons;
std::vector<Chemistry::Ion> CorrectIons;
std::vector<Chemistry::Ion> CorrectIons2;
std::vector<Chemistry::Ion> FinishedIons;
std::vector<Chemistry::Ion> UnrankedIons;

bool Playing = true;

int HasElement(const std::vector<Chemistry::Ion>& Vector, const Chemistry::Ion& Element) {
    for (int i = 0; i < Vector.size(); i++) {
        if (Vector[i] == Element) {
            return i;
        }
    }
    return -1;
}

void Promote(Chemistry::Ion & Ion) {
    if (HasElement(FailedIons, Ion) != -1) {
        FailedIons.erase(FailedIons.begin() + HasElement(FailedIons, Ion));
        CorrectIons.push_back(Ion);
        return;
    } else if (HasElement(CorrectIons, Ion) != -1) {
        CorrectIons.erase(CorrectIons.begin() + HasElement(CorrectIons, Ion));
        CorrectIons2.push_back(Ion);
        return;
    } else if (HasElement(CorrectIons2, Ion) != -1) {
        CorrectIons2.erase(CorrectIons2.begin() + HasElement(CorrectIons2, Ion));
        FinishedIons.push_back(Ion);
        return;
    } 

    UnrankedIons.erase(UnrankedIons.begin() + HasElement(UnrankedIons, Ion));
    CorrectIons.push_back(Ion);
    return;
}


void Demote(Chemistry::Ion & Ion) {
    if (HasElement(CorrectIons, Ion) != -1) {
        CorrectIons.erase(CorrectIons.begin() + HasElement(CorrectIons, Ion));
        FailedIons.push_back(Ion);
        return;
    } else if (HasElement(CorrectIons2, Ion) != -1) {
        CorrectIons2.erase(CorrectIons2.begin() + HasElement(CorrectIons2, Ion));
        CorrectIons.push_back(Ion);
        return;
    } else if (HasElement(UnrankedIons, Ion) != -1) {
        UnrankedIons.erase(UnrankedIons.begin() + HasElement(UnrankedIons, Ion));
        FailedIons.push_back(Ion);
        return;
    }
}

std::string CurrentRank(const Chemistry::Ion& Ion) {
    if (HasElement(FailedIons, Ion) >= 0) {
        return "1x Fout";
    } else if (HasElement(CorrectIons, Ion) >= 0) {
        return "1x Goed";
    } else if (HasElement(CorrectIons2, Ion) >= 0) {
        return "2x Goed";
    } else if (HasElement(FinishedIons, Ion) >= 0) {
        return "3x Goed";
    }

    return "Not found";
}

Chemistry::Ion GetRandomNonFinishedIon() {
    Chemistry::Ion randomIon;
    do {
        randomIon = Chemistry::GetRandomIon();
    } while (HasElement(FinishedIons, randomIon) != -1);
    return randomIon;
}

void AskQuestion() {
    Chemistry::Ion Answer = Chemistry::GetRandomIon();

    if (FinishedIons.size() == Ionen::Ions.size()) {
        Playing == false;
        return;
    }

    if (HasElement(FinishedIons, Answer) != -1) {
        return;
    }

    std::cout << "Wat is de formule van " << Answer.Naam << std::endl;

    std::string formule;
    std::string lading;

    Chemistry::Ion GivenAnswer;

    std::cin >> formule >> lading;

    GivenAnswer.Formule = formule;
    GivenAnswer.Lading = lading;
    GivenAnswer.Naam = Answer.Naam;

    if (Answer == GivenAnswer) {
        Promote(Answer);
        std::cout << "\nGoedzo!\n" << CurrentRank(Answer) << std::endl << std::endl;
    } else {
        Demote(Answer);
        std::cout << "\nVolgende keer beter" << std::endl << std::endl << "Het goede antwoord was: " << Answer.Formule << " " << Answer.Lading << std::endl
        << std::endl << CurrentRank(Answer) << std::endl << std::endl;
    }

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}


int main() {
    while (true) {
        FailedIons.clear();
        CorrectIons.clear();
        CorrectIons2.clear();
        FinishedIons.clear();
        UnrankedIons.clear();

        for (const auto& ion : Ionen::Ions) {
            UnrankedIons.push_back(ion);
        }

        int choice;

        do {       
            std::cout << "0. Stop" << std::endl << "1. Oefen" << std::endl;
            std::cin >> choice;

            switch (choice) {
                case 0:
                    std::cout << "Afbreken..." << std::endl;
                    return 0;
                case 1:
                    std::cout << "\n";

                    while (FinishedIons.size() != Ionen::Ions.size()) {
                        AskQuestion();
                    }

                    std::cout << "Je hebt alles 3x goed! Goed gedaan!" << std::endl << std::endl;

                    break;
                }
        } while (choice != 0);
    }
}