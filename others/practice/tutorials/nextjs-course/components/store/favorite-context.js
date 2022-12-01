import { createContext, useState } from "react";

const favoritesContext = createContext({
  favorites: [],
  totalFavorites: 0,
  addFavorites: (favoroteMeetup) => {},
  removeFavorite: (meetupId) => {},
  itemIsFavorite: (meetupId) => {},
});

export const FavoritesContextProvider = (props) => {
  const [userFavorites, setuserFavorites] = useState([]);
  const addFavoriteHandler = (favoriteMeetup) => {
    setuserFavorites((prevState) => {
      return prevState.concat(favoriteMeetup);
    });
  };
  const removeFavoritesHandler = (meetupid) => {
    setuserFavorites((prevState) => {
      return prevState.filter(meetupid !== prevState.id);
    });
  };
  const isMeetupFavorite = (meetupid) => {
    return userFavorites.some((meetup) => meetup.id === meetupid);
  };

  const context = {
    favorites: userFavorites,
    totalFavorites: userFavorites.length,
    addFavorites: addFavoriteHandler,
    removeFavorites: removeFavoritesHandler,
    itemIsFavorite: isMeetupFavorite,
  };
  return (
    <favoritesContext.Provider value={context}>
      {props.children}
    </favoritesContext.Provider>
  );
};

export default favoritesContext;