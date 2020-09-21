const address = "../public/images/"
const source = document.querySelector('#summerShows').innerHTML;
const template = Handlebars.compile(source);
const context = {
  summerAnimes: [
        {
            name: "Re:Zero - Starting Life in Another World",
            src: "https://u.livechart.me/anime/9387/poster_image/d30e2340c85c78a467e60ff4173994c2.jpg?style=small&format=jpg",
            link: "https://www.crunchyroll.com/rezero-starting-life-in-another-world-"
        },
        {
            name: "The God of High School",
            src: address + "godOfHighSchool.jpg",
            link: "https://www.crunchyroll.com/the-god-of-high-school"
        },
        {
            name: "The Misfit of Demon King Academy",
            src: address + "demonKingAcademy.jpg",
            link: "https://www.crunchyroll.com/the-misfit-of-demon-king-academy"
        },
    ]
};   
const compiledHtml = template(context);
const fill = document.querySelector("#summerseason");
fill.innerHTML = compiledHtml;