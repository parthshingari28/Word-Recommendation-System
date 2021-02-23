#include <stdio.h>
#include<string.h>
#include<stdlib.h>

struct node
{
    char *string;
    int priority;
    struct node* next;
};
struct node* head;
struct node* getnewnode(char *s,int p)
{
    struct node* newnode = malloc(sizeof(struct node));   // don't cast return value of malloc
    newnode->string = strdup(s);   // create copy of given string
    newnode->priority = p;
    newnode->next = NULL;

    return newnode;
}

void TraverseList() // showing list
{
    struct node *temp;

    // Return if list is empty
    if(head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    temp = head;
    while(temp != NULL)
    {
        printf("word = %s\n", temp->string); // Print data of current node
        printf("priority = %d\n", temp->priority);
        temp = temp->next;                 // Move to next node
    }
}

void push(char* str,int p)
{
    struct node* node1 = getnewnode(str,p);
    if(head==NULL)
    {        //if the element is inserted in empty list
        head = node1;
        return;
    }

    if(head->priority < p )
    {
        node1->next = head;
        head = node1;
    }

    else
    {
        struct node* temp = head;
        while(temp -> next != NULL && temp -> priority >= p)
        {
            temp = temp->next;
        }

        node1->next = temp->next;
        temp->next = node1;
    }
    TraverseList();
}

void pop()
{
    struct node* temp=head;
    head=head->next;
    free(temp);

}

/* function to swap data of two nodes a and b*/
void swap(struct node *a, struct node *b)
{
    char  temp_word[20];
    int temp_priority;

    strcpy(temp_word, a -> string);
    temp_priority = a -> priority;

    a -> priority = b -> priority;
    strcpy(a -> string, b -> string);

    b -> priority = temp_priority;
    strcpy(b -> string, temp_word);
}


void bubbleSort()
{
    int swapped, i;
    struct node *ptr1;
    struct node *lptr = NULL;

    /* Checking for empty list */
    if (head == NULL)
        return;

    do
    {
        swapped = 0;
        ptr1 = head;

        while (ptr1->next != lptr)
        {
            if (ptr1 -> priority < ptr1 -> next -> priority)
            {
                swap(ptr1, ptr1->next);
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    }
    while (swapped);
}


void inc(char* str)
{
    struct node *temp;

    if(head == NULL)
    {
        //printf("List is empty.");
        return;
    }

    temp = head;
    while(temp != NULL)
    {
        if(strcmp(str, temp -> string) == 0)
            temp -> priority += 1;
        temp = temp->next;
    }
    bubbleSort();
}


int traverseList(char* str, int n) // everything
{
    struct node *temp;
    int j, i=1, t;
    char word[10][20];

    if(head == NULL)
    {
        //printf("List is empty.");
        return 0;
    }

    temp = head;
    while(temp != NULL)
    {
        for(j=0;j<n;j++)
        {
            if(str[j] == temp -> string[j])
            {   if(j==(n-1))
                {
                    strcpy(word[i-1], temp -> string);
                    printf("%s index=%d\n", temp -> string, i);
                    i++;
                }
            }
            else { break ;}

        }
        temp = temp -> next;
    }

    printf("\nGive index of your word: (if want to search for new word in dictionary enter 0)\t");
    scanf("%d",&t);


    if(t == 0)
        return 0;
    else
    {
        printf("\nYour choice is %s", word[t-1]);
        printf("\n%s", word[t-1]);
        inc(word[t-1]);
        return 1;
    }


}

void peek()
{
    printf("\n%s", head->string);
    printf("\n%i", head->priority);
}

void write_in_file(char *name)
{
    FILE *fptr;
    fptr = fopen(name, "w");
    struct node *temp;
    temp = head;

    struct data
        {
            char string[20];
            int priority;
        }var;

    while(temp != NULL)
    {
        strcpy(var.string, temp -> string);
        var.priority = temp -> priority;

        fwrite (&var, sizeof(var), 1, fptr);
        temp = temp->next;                 // Move to next node
    }
    fclose(fptr);
}

int main()
{
    head=NULL;

    int i=0,j=0,t,r,u;
    long n;
    char str[20],name[20];
    printf(":::::::::::::::::::::::::WELCOME TO WORD RECOMMENDATION SYSTEM:::::::::::::::::::::::::\n\n\n\n\n");
    printf("Are You a:\n 1 - Existing User \n 2 - New User \t please write corresponding number\n\n");
    scanf("%d", &u);
    if(u == 1)
    {
        FILE *fptr;

        printf("Write your name\n\n");
        scanf("%s",name);
        fptr = fopen(name, "r");

        struct data
        {
            char string[20];
            int priority;
        }var;

        if (fptr == NULL)
        {
            fprintf(stderr, "\nError opening file\n");
            exit (1);
        }
        while(fread(&var, sizeof(var), 1, fptr))
        {
            push(var.string, var.priority);
        }

        fclose(fptr);

    }
    else
    {
        printf("Write your name\n\n");
        scanf("%s",name);

    }



    char lib[][20]={ "apple" , "application" , "appy" , "ability","able","aboard","about","above","abroad","absolutely","abuse","accelerate","accept","access","accessible","accident","account","accounted","accounting","accurate","accused","achieve","acquire","acquistion","across","action","active","actively","activist","activits","activity","actual","actually","addition","additional","address","adjust","adopt","adoption","adult","advance","advantage","advertisers","advice","affect","afford","affordable","after","afternoon","again","against","agency","agent","aggressive","agree","agreement","ahead","aircraft","airline","airport","airstrikes","alert","alive","allegedly","allow","almost","alone","along","alongside","already","also","alternative","although","always","amid","among","amount","analysis","analyst","analytics","analyze","ancient","angry","animal","anniversary","announce","announcement","annual","anoymity","anonymous","another","answer","antitrust","anyone","anything","anywhere","apart","apartment", "apparent" ,"apparently" ,"appeal" ,"appear", "appearance" ,"apply" ,"approach"," appropriate" ,"approval" ,"apps" ,"architecture" ,"area" ,"argue" ,"argument", "army", "around", "array" ,"arrest", "arrival", "arrive", "article" ,"aside" ,"aspect" ,"assault" ,"asset" ,"assistance"," assistant"," associate"," assume"," atmosphere"," attack"," attacker", "attempt" ,"attend"," attention"," attorney" ,"attract"," attractive" ,"auction", "audience", "audio", "author", "authority" ,"auto" ,"automatic" ,"automation" ,"autonomous", "availability", "available", "average", "avoid", "aware", "awareness", "away", "baby" ,"back", "backdrop" ,"backed", "background" ,"backing" ,"backlash" ,"backpack" ,"backup" ,"badly" ,"bail" ,"bailout", "balance", "ball", "ballot", "band", "bandwidth", "bank" ,"banking", "bankruptcy" ,"barely", "barrel", "barrier" ,"base", "baseball" ,"based", "basic", "basically" ,"basis" ,"basketball" ,"bass" ,"bathroom" ,"battery", "battle", "battlefield", "battling", "beach", "bear" ,"beautiful", "beauty" ,"because", "beer" ,"before", "begin", "beginning", "behalf" ,"behaviour", "behind"," belief" ,"believe", "belong", "below" ,"benchmark", "beneath" ,"benefit",  "best" ,"beta" ,"better", "between", "beyond", "bigger" ,"biggest" ,"bike", "bill", "billing", "billion", "billionaire", "biometric", "bird", "birth" ,"birthday" ,"bitcoin", "bitcoins", "black", "blame" ,"blast", "blaze" ,"blind" ,"block", "blocked" ,"blocking" ,"blog" ,"blood" ,"bloody", "blow", "blue", "board", "boat", "body" ,"bold", "bolster", "bomb", "bomber", "bombings" ,"bond", "bone", "bonus", "book" ,"boom" ,"boost", "boot", "border" ,"born", "boss" ,"both" ,"bottle" ,"bottom" ,"brain" ,"branch" ,"brand", "breach", "breached", "break", "breakthrough", "bridge", "brief", "briefing", "briefly" ,"bright", "brightness", "brilliant", "bring" ,"broad", "broadband", "broadcasters", "broader", "broadly", "broker", "brother", "brown", "browser" ,"browse" ,"brush", "brutal" ,"bubble", "budget", "build", "bulk", "bullet", "bunch", "bundle", "bundled", "burden" ,"burn" ,"business" ,"busy", "button" ,"buyer", "buzz" ,"bypass", "cable", "calendar", "call", "camera", "campaign", "cannot", "capability", "capable", "capacity", "capital" ,"capture", "carbon", "card"," care", "carrier" ,"carry" ,"case", "cash", "catch" ,"category", "cause" ,"caused" ,"causing" ,"cell" ,"cellular", "centre", "central", "century" ,"certain", "certainly", "chain", "chairman" ,"challenge" , "chance" ,"change" ,"channel", "charge" ,"cheap", "cheaper", "check" ,"chemical", "chief", "child" ,"chip", "choice", "choose", "church" ,"city" ,"civil", "claim" ,"class" ,"clean", "clear" ,"clearly", "click", "client", "climate" ,"close", "closely" ,"closer", "cloud", "coalition" ,"coast", "code", "cold", "collect"," collection", "college" ,"color", "combat", "combination", "comfortable", "command", "comment", "commercial", "commitment" ,"committee", "common", "communicate", "community", "company", "comparison", "compatible", "compete", "competition", "competitive", "complaint", "complete", "completed", "completely", "complex", "compromised", "computer", "concept", "concern", "condition", "conduct", "conducted", "conference", "confidence", "conflict", "connect", "connection" ,"connections", "connectivity" ,"conservative", "consider", "consistent", "console", "construction", "consumer", "contact", "contain", "content" ,"continue", "contract", "contrast", "control", "controlled", "conversation", "cool", "copy", "core", "corporate", "cost", "could", "count", "country" ,"couple", "course", "court", "code", "cover", "coverage", "crash", "create", "creation", "creative", "credit", "crime", "criminal", "crisis" ,"critical", "criticism", "crowd", "culture", "currency" ,"current", "currently", "custom", "customer" , "data", "database", "date", "daughter", "dead", "deadline", "deadly", "deal" ,"death", "debate", "debit", "debris", "debt", "debut", "decade", "decent", "decide" ,"decision" ,"decline", "deep", "deeper", "deeply", "default", "defeat" ,"defence", "defend" , "defender", "defence", "deficit", "define" ,"definitely", "definition", "degree", "delay", "delete", "deliver", "delivery", "demand", "demanded", "demanding" ,"demo", "democracy" ,"demonstrate", "deny" ,"department", "departure" ,"depend", "deploy", "deployment", "depth", "deputy", "describe", "description", "desert", "design" ,"designer" ,"desire", "desk", "desktop" ,"desperate","despite" ,"destination", "destroy", "destruction", "detail", "detailed", "detect"  ,"detection", "detention", "determine", "develop" ,"developer", "development", "device", "dialogue", "difference" ,"different", "difficult", "difficulty" ,"digital", "dinner", "dinosaur", "diplomatic", "direct", "direction", "directly" ,"director" ,"disable", "disaster", "disclose", "disclosure" ,"discount" ,"discover", "discovery" ,"discuss", "discussion", "disease", "disk", "display", "dispute", "disputed", "disrupt", "disruption", "distance" ,"distant" ,"distribute", "distribution" ,"district", "diverse" ,"diversity", "division" ,"dock" ,"doctor" ,"document" ,"dollar", "domain" ,"domestic", "dominant" ,"door", "double", "doubt", "down", "download", "downtown", "dozen", "draft", "drag", "dramatic" ,"dramatically", "draw" ,"dream" ,"drive", "driver", "drone", "drought" ,"drug", "dual", "during" ,"dust" ,"duty" ,"dynamic", "each", "eager", "earlier", "early", "earn", "earnings", "earthquake", "ease" ,"easier", "easily", "easing", "east", "eastern", "easy", "economic", "economist", "economy", "ecosystem", "edge", "edit", "edition", "editor", "education", "educational", "effect", "effective", "effectively", "efficiency","efficient", "effort", "eight", "either", "election", "electric", "electrical", "electricity", "electronic", "electronics", "element", "eligible", "eliminate", "else", "elsewhere", "email", "emails", "embrace", "emergency", "emotional", "employee", "employment", "empty", "enable", " encourage", "encryption", "ended", "ending", "enemy", "energy", "engage", "engagement", "engine", "engineer", "engineering", "enhance", "enjoy", "enormous", "enough", "ensure", "enter", "enterprise", "entire", "entirely", "entry","environment", "equal", "equally", "equipment", "equity", "equivalent" ,"error", "escape", "especially", " estimate", "ethnic", "euro", "euros", "even", "evening", "event", "eventually", " every", "everybody" ,"everyday", "everyone", "everything", "everywhere", "evidence", " evolution", "exact", "exactly", "examine", "example", "excellent", "except", "exception", "exchange", "exclusive", "execute", "execution", "executive", "executives", "exercise", "exist", "existence", "exit", "expand", "extension", "except", "expand", "expansion", "expect", "expense", "expensive" ,"experience", "experienced", "experiment", "expert", "expertise", "explain" ,"explanation", "exploit" ,"exploration", "explore", "explosion", "export", "exposure", "express", "extension", "extensive", "extent", "external", "extra", "extract", "extreme" ,"extremely", "extremist", "face", "facial", "facilitate", "facility", "factor","fact"," factory", "failure", "fair", "fairly","faith", "fake", "fall", "false", "familiar", "family", "famous", "farm", "fashion", "fast", "faster" , "fastest" ,"fatal" ,"fate", "father", "fault", "favour", "favourite", "fear", "feared", "feature", "federal", "feed", "feedback", "feel", "feet", "fellow" ,"female", "ferry", "fewer" ,"fibre" , "field" , "fierce" ,"fifth", "fight" ,"fighter", "figure" ,"file" ,"filed", "filing", "fill" ,"film" ,"filter" ,"final", "finally", "finance", "financial" ,"financing", "find" ,"fine", "fines", "finger" ,"fingerprint" ,"finish", "fire" ,"fired" ,"firefighters" ,"firing" ,"firm", "firmware", "first", "fiscal", "fish", "fishing" ,"fitness", "fits", "five", "flag", "flagship" ,"flash", "flat", "flaw" ,"fleet", "flexibility" ,"flexible" ,"flight", "flip", "flood" ,"floor" ,"flow", "focus" ,"focuses", "focusing" ,"folder", "folks", "follow", "food", "footage" ,"football", "footprint", "force" ,"forced", "forcing", "forecast", "foreign", "forget", "form", "formal", "formally", "format", "former", "formerly", "forth", "forum", "forums", "forword", "fossil", "foundation", "founder" ,"four" ,"fourth", "fraction", "frame", "framework", "fraud", "free", "freedom", "freely", "frequency", "frequent", "frequently", "fresh", "friend", "friendly", "from", "front", "frustration",  "fuel", "full", "fully", "function", "functional", "fund", "fundamental", "funeral", "further", "future", "gadget", "gain", "galaxy", "gallery" ,"gallon", "game" ,"gameplay" ,"gamer" ,"gamers" ,"gamut", "gang" ,"garage", "garbage", "garden", "garment", "garner", "gasoline" ,"gate" ,"gateway", "gather", " gays" ,"gauge", "gaze", "gear","geared","gearing","geek","gender","gene","general","generally","generals","generate","generation","generator","generic","generous","genetic","genetically","genius","genocide","genome","genre","gentle","gently","genuine","genuinely","geographic","geographical","geography","geological","geopolitical","gesture","ghost","giant","gift","gigabit","gigabyte","gigantic","girl","girlfriend","give","giveaway","glad","glance","glass","glimpse","glitch","global","globally","globe","glory","glossy","glove","glow","glucose","glue","goal","gold","golden","golf","gonna","good","goodbye","goods","gorgeous","gotten","govern","governance","government","governmental","governor","grab","grace","grade","gradual","gradually","graduate","graduation","grain","grand","grandfather","grandmother","grant","granular","graph","graphic","graphical","graphics","grasp","grass","grateful","grave","gravity","gray","great","greater","greatest","greatly","green","greenhouse","grenade","grey","grid","grief","grim","grip","grocery","gross","grounded","groundwater","groundwork","group","grow","growth","gruesome","guarantee","guaranteed","guard","guess","guest","guidance","guide","guilt","guilty","guitar","gunfire","gunman","gunned","gunshot","habit" ,"habitat", "hack", "hacker", "hailed", "hair", "half", "halfway", "hall", "halt", "hampered", "hand", "handful", "handheld", "handle", "handset", "handy", "hang", "happen", "happy", "harassment", "hard", "harder", "hardest", "hardly", "hardware", "harm", "harmful", "hardness", "harsh", "harvest", "hashtag", "hashtags", "hassle" ,"hate", "have", "heaven", "hazardous", "head", "headline", "headphone", "headphones", "headset",  "health" ,"healthcare", "healthy", "hear", "heart",  "heat", "heating", "heavier", "heavily", "heavy", "hadge", "hefty", "height", "helicopter", "hell", "helm", "helmet", "help", "helpful", "hear", "heritage", "hero", "heroin", "herself", "hgroup", "hide", "high", "higher", "highest", "highlight", "highlighted", "highlighting", "highly", "highs", "highway", "hike", "himself", "hint", "hinted", "hire", "historic", "historical", "historically",  "history", "hockey", "hold", "holder", "hole", "holiday", "holy", "home", "homeless", "homeowner", "hometown", "homeside", "honest", "honor", "honored", "hook", "hooked", "hope", "hopefully", "hoping", "horizon", "horizontal", "horrible", "horrific", "horror", "horse", "horses", "hospital", "hospitalized", "host", "hostage", "hosted", "hostile", "hosting", "hotel", "hotspot", "hotspots", "hottest", "hour", "hourly", "household", "housing", "however", "huge" ,"hugely", "human", "humanitarian", "humanity", "humans", "humidity" ,"hundred", "hunger", "hunt", "hurdle", "hurricane", "husband", "hybrid", "hydrogen", "hype", "icon", "iconic", "idea", "ideal", "identical", "identify", "identity", "ignore", "illegal", "illegally", "illness", "imminent", "impact" ,"impacted", "implement", "implemented", "implementing", "import", "importance", "important", "importantly", "impose", "impossible", "impression", "impressive", "improve", "improvement", "inbox", "incentive", "inch", "incident", "include", "inclusion", "income", "incoming", "incorporate", "increase", "increasingly", "incredible", "incredibly", "incremental", "indeed", "independence", "independent", "index", "indicate", "indication", "indicator", "indictment", "individual", "individuals", "industrial", "industry" ,"inevitable", "inexpensive", "infection", "inflation", "influence", "influential", "info", "inform", "information", "infrared", "infringement", "initial" ,"initially", "initiative", "injury", "inmate", "inner", "innocent" ,"innovation", "innovative", "input", "inquiry", "insert", "inside", "insight", "inspection", "inspire", "install" ,"installation", "installer", "instance", "instant", "instantly", "instead" ,"institution", "instrument", "insurance" ,"insurgency", "insurgents", "integrate" ,"integration", "integrity" ,"intellectual", "intelligence" ,"intelligent", "intend" ,"intense", "intent", "intention", "interact", "interaction", "interactive", "intercept", "interest", "interested", "interesting", "interface", "interference" ,"interim", "interior" ,"internal" ,"internally", "internet", "intervention", "interview", "interviewed", "into", "introduce" ,"introduction", "intrusion", "intuitive", "invasion", "inventory", "invest", "investigate", "investigator" ,"investment" ,"investor", "investors", "involve", "involvement", "iron"," island", "isolation", "issue" ,"issued", "issuing"," item ","itself"};

    //for(i=0;i<3;i++)
   // {
    //    printf("string= %s \t address= %d \t\n\n",lib[i],lib+i);
   // }
   //
    int dict_len = *(&lib + 1) - lib;

    do
    {
        printf("Please type letters to find a similar word\n\n");
        scanf("%s",str);

        n = strlen(str);

        int a = 0;
        printf("Similar words are\n\n");

        if(head != NULL)
        {
            a = traverseList(str, n);
        }

        if(a == 1) {}

        else

        {
            for(i=0; i<dict_len; i++)
            {
                for(j=0;j<n;j++)
                {
                    if(str[j]==lib[i][j])
                    {   if(j==(n-1))
                            printf("%s index=%d\n\n",lib[i],i);
                    }
                    else
                    {
                        //printf("\nSImilar word not found,Do you want to insert a new word\t");
                        break ;
                    }
                }

            }
            printf("Give index of your word\t\n\n");
            scanf("%d",&t);
            printf("Your choice is %s\n\n",lib[t]);
            push(lib[t],1);
        }
        printf("If you want to search another word type 1 , if you want to exit press 0 \t\n\n");
        scanf("%d",&r);

    } while(r == 1);

    TraverseList();
    write_in_file(name);

    return 0;
}
