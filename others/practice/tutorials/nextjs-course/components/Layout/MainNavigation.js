import { useContext } from "react";
import { NavLink } from "react-router-dom";
import favoritesContext from "../../store/favorite-context";
import classes from './MainNavigation.module.css';
const MainNavigation = () => {
    const favCtx = useContext(favoritesContext);
  return (
    <header className={classes.header}>
      <div className={classes.logo}>React Meetups</div>
      <nav>
        <ul>
          <li>
            <NavLink to="/">All Meetups</NavLink>
          </li>
          <li>
            <NavLink to="/new-meetup">New Meetups</NavLink>
          </li>
          <li>
            <NavLink to="/favorites">Favorites</NavLink>
            <span className={classes.badge}>{favCtx.totalFavorites}</span>
          </li>
        </ul>
      </nav>
    </header>
  );
};
export default MainNavigation;
