#include "stdafx.h"

#pragma once

#include "registerUser.h"
#include "theatre.h"
#include "movie.h"

#include "userRating.h"
#include "userComment.h"
#include "userData.h"

int main()
{
	// create a new theatre object
	Theatre uweTheatre("UWE Frenchay");

	// register a user with the theatre and add some user details
	RegisterUser user1 = uweTheatre.RegisterAUser("user1@here.com", "password");
	user1.AddUserData("user1", "bristol", "1234");

	// add a favourite movie for the user1
	Movie fightClub = user1.AddMovie("Fight Club", 1999, "An insomniac office worker crosses paths with a devil-may-care soap maker forming an underground fight club", "Drama");

	// add a comment about and a rating for the Fight Club movie
	UserComment comment1 = fightClub.AddComment("What a cool film with a suprising twist!");
	fightClub.AddMovieRating(5);

	// increment the number of times the comment has been read and give it a thumbs up
	comment1.IncrementTimesRead();
	comment1.IncrementThumbsUp();

	return 0;
}