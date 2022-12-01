// our-domain.com/news/

import Link from 'next/link';
import { Fragment } from "react";

function NewsPage() {
  return (
    <Fragment>
      <h1>The News Page</h1>
      <ul>
        <li>
        {/* if it is a single page application, we want to stay rather sending new request to backend to fetch a new html page
        instead of 'a href', use 'Link href'
          goes to the page without fetching a new page, but a SPA is just rerendered by React
          !!! IMPORTANT !!! (for staying in a single page application) */}
          <Link href="/news/nextjs-is-a-great-framework">
            NextJS Is A Great Framework
          </Link>
        </li>
        <li>Something Else</li>
      </ul>
    </Fragment>
  );
}

export default NewsPage;
