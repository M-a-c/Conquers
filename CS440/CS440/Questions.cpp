#include "Questions.hpp"

int Questions::getNextQuestion(){

	return Counter++;//First Value Returned is 0.
}

void Questions::setQuestion(int c){
	Counter = c;
}

void Questions::gameInit(){
		WWII[0] = "In 1939, the Battle of the Atlantic was waged between the Allies and Germany. This battle consisted of primarily ***** warfare, and lasted until the year ****. \
		This battle waged on as a war of attrition with the goal of cutting off ***** and **** to the Allies in the Western front.";

		WWII[1] = "Early in the year of 1940, the Axis powers advanced their forced towards France, which would be the start of the Battle of France.\
		To make their way into France, Axis forces invaded the Low Counties along the way, which included Belgium and the *****.\
		Germany, with the assistance of the *****, managed to outflank the ***** Line, and make their way into France.\
				The Battle of France would end after the Allies took a defeat in the French capital of *****.";

		WWII[2] = "After the Battle of France in 1940, the Axis powers proceeded into Great Britain, marking the beginning of the Battle of Britain.\
		British icon ******* served as Prime Minister for the British, and was in charge during the German air raids known as The *****\
		The Germans prioritized ***** bases as attack targets, but ultimately failed due to their inability to commit ground units that were\
		fighting on the ***** front.";

		WWII[3] = "In August of 1942, the Battle of Stalingrad began, and is considered to be one of the most decisive battles in the war.\
		German forced invaded Staligrad, seeking a strategic victory due to its location near the ***** River.\
		Germans also sought an idealistic victory, as the city was named after Russian leader *****\
		The battle lasted 5 months, with Germans controlling *****% of the city at times, but the Germans could not seize victory.\
		Winter set in, and Germany suffered a crippling defeat at the hands of the ***** Army, and Operation Barbarossa was all but over.";

		AnswersWWII[0] = "A.Ground, 1941, Food, Shelter\
		B.Aerial, 1943, Money, Women\
		C.Naval, 1945, Supplies, Technology";

		AnswersWWII[1] = "A.Cayman Islands, French, Grand, Yemen\
		B.Netherlands, Italians, Maginot, Paris\
		C.Netherlands, Russians, Maginot, Marseille";

		AnswersWWII[2] = "A.Winston Churchill, Drop, Royal Air Force, Northern\
		B.Winston Churchill, Blitz, Royal Air Force, Eastern\
		C.John Lennon, Drop, Royal Navy, Cold, FALSE";

		AnswersWWII[3] = "A.Volga, Joseph Stalin, 90 \
		B.Mississippi, Vladimir Putin, 33, Red Ribbon\
		C.Volga, Joseph Stalin, 75, Red";

		AnswersWWII[0] = C;
		AnswersWWII[1] = B;
		AnswersWWII[2] = B;
		AnswersWWII[3] = A;

		Roman[0]="In the year 59 BC,  Governor ***** sought to stir up the political climate, and to this end, began his plot to incite the ***** wars.\
		By taking advantage of the publics fears relating to the sack of Rome by Gaul, he rallied the public to support his cause.\
		In 58 BC, the **** and **** tribes of Gaul were found on a route leading to Rome, and Caesar used this as an excuse to incite war.\
		Caesar went on a ruthless campaign, slaughtering all the tribes of Gaul and taking all of the Gallic territory for himself.The Gallic\
		people were assimilated into the Roman Empire.";

		Roman[1] = "In 59 BC, Julius Caesar and his contemporaries Marcus Licinius Crassus and ***** the Great formed the First *****.\
		While this alliance created a political balance in Rome, it was uneasy at best, and would not last long.\
		Crassus would launch an invasion on the ***** Empire, and end up losing his head(literally).His head was\
		brought before the Parthian royal court and used as a prop in a Parthian play(You can't make this stuff up.)\
		The death of Crassus disrupted the uneasy political balance between Julius Caesar and his political contemporaries.";

		Roman[2] = "In 49 BC, Pompey the Great thought he was all that and a bag of chips, and took political control of Rome during Julius Caesar's absence. \
		This lead to Caesar's crossing of the *****, as he returned to Rome to take what was rightfully his. This lead to another great ***** War in Rome. \
		With Caesar closing in, Pompey ordered the abandonment of Rome, because he missed the whole 'fight like a man' thing.Julius chased in hot pursuit, targeting the \
		Pompeian stronghold of *****.Despite having a 2:1 military advantage, Pompey the Great was defeated in battle, and fled to Egypt.Upon arriving,\
		Pompey was murdered by the Egyptians, because they, like everyone else, were afraid of Caesar's wrath. ";

		Roman[3] = "In 44 BC, Julius Caesar earned a reputation around the world for flexing all of his opponents.This reputation\
		lead people to fear that he has become to powerful, so a group of anti - Caesarians called The ***** assassinated Julius Caesar,\
		ending his almighty reign.This event created a massive power vacuum that was ultimately filled by his adopted son, *****.\
		Caesar's son was joined by contemporaries ***** and Lepidus. However, much like the First Triumvirate, the members of the \
		Second Triumvirate could not find any non - violent hobbies, so another Civil War errupted.Antony and Lepidus fell, Octavian took\
		upon the name Augustus, and the Roman ***** was born.";


		AnswersRoman[0] = "A: Rod Blagojevic, Star, Helvetti, Tigurini \
		B: Augustus, Gallic, Helvetti, Tigurini\
		C: Julius Caesar, Gallic, Helvetti, Tigurini";

		AnswersRoman[1] = "A: Alexander, Ammendment, Galactic \
		B: Pompey, Triumvirate, Parthian\
		C: Bernie Sanders, Triumvirate, Chinese";

		AnswersRoman[2] = "A: Rubicon, Civil, Iberia \
		B: Rubix Cube, Star, Pompe\
		C: Nile River, Civil, Iberia";

		AnswersRoman[3] = "A: Powerpuff Girls, Gaius Octavian, Mark Anthony, Catholic Church \
		B: Justice League, Doctor Octopus, Mark Antony, Empire \
		C: Liberators, Gaius Octavian, Mark Antony, Empire ";

		AnswersRoman_Select[0] = C;
		AnswersRoman_Select[1] = B;
		AnswersRoman_Select[2] = A;
		AnswersRoman_Select[3] = C;

}