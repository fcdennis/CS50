const source = document.querySelector("#seasonshow");
const template = Handlebars.compile(source);

const context = {
    anime: [
        {
            name: 'Food Wars!',
            source: "public/img/foodWars.jpg",
            link: "https://www.crunchyroll.com/food-wars-shokugeki-no-soma",
            season: 'Summer'
        },
        {
            name: 'Re:Zero',
            source: "public/img/reZeroalt.jpg",
            link: "https://www.crunchyroll.com/rezero-starting-life-in-another-world-",
            season: 'Winter'
        },
        {
            name: 'My Teen Romantic Comedy',
            source: "public/img/myTeenRomanticComedy.jfif",
            link: "https://www.crunchyroll.com/my-teen-romantic-comedy-snafu",
            season: 'Summer'
        },
        {
            name: 'Fruits Basket',
            source: "public/img/fruitsBaskets.jpg",
            link: "https://www.crunchyroll.com/pt-br/fruits-basket",
            season: 'Spring'
        },
        {
            name: 'Haikyu',
            source: "public/img/haikyuu.jpg",
            link: "https://www.crunchyroll.com/haikyu",
            season: "Fall"
        }
    ]
};

const compileHtml = template(context);

document.querySelector(".shows").innerHTML = compileHtml;